#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<int> graph[500 + 1];
int indegree[500 + 1] = { 0, };
int times[500 + 1];

void topologySort() {
	queue<int> q;
	vector<int> result(501); // 결과 저장하고 출력하기 위함
	for (int i = 0; i < 501; i++) {
		result[i] = times[i];
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			result[graph[now][i]] = max(graph[now][i], result[now] + times[graph[now][i]]);
			indegree[graph[now][i]]--;

			if (indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		times[i] = t;

		while (true) {
			int x;
			cin >> x;
			if (x == -1) break;
			indegree[i]++;
			graph[x].push_back(i);
		}
	}

	topologySort();

	return 0;
}