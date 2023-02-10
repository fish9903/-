#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

vector<int> food_times;

// 오름차순
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	food_times.push_back(3);
	food_times.push_back(1);
	food_times.push_back(2);

	int k = 5; 
	int answer;
	
	ll sum = 0; // 음식 먹는데 걸리는 총 시간
	for (int i = 0; i < food_times.size(); i++) {
		sum += food_times[i];
	}
	if (sum <= k) return -1;

	// time, index
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < food_times.size(); i++) 
		pq.push({food_times[i], i});

	ll cycle = pq.size();
	ll cycle_time = 0;
	ll total_cycle_time = 0;
	while (1) {
		cycle_time = pq.top().first - total_cycle_time;
		total_cycle_time += cycle_time;

		k -= cycle * cycle_time;
		if (k < 0) {
			k += cycle * cycle_time;
			total_cycle_time -= cycle_time;
			break;
		}
		pq.pop();
		cycle--;
	}

	vector<pair<int, int>> v;
	while (!pq.empty()) {
		int time = pq.top().first - total_cycle_time;
		int index = pq.top().second;

		v.push_back({ time, index });
		pq.pop();
	}
	sort(v.begin(), v.end(), compare);

	answer = v[k % v.size()].second + 1;

	cout << answer << endl;

	return 0;
}