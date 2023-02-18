#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> house;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		house.push_back(x);
	}

	sort(house.begin(), house.end());

	cout << house[(house.size() - 1) / 2];

	return 0;
}