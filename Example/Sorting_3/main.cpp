#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int sum = 0;
	while (pq.size() != 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		sum += a + b;
		pq.push(a + b);
	}

	cout << sum;

	return 0;
}