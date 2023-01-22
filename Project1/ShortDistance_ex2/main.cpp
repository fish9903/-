#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int n, m, c;
vector<pair<int, int>> graph[30000 + 1];
int d[30000 + 1];

void Dijstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int dist = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (d[node] < dist) continue;
		for (int i = 0; i < graph[node].size(); i++) {
			int cost = dist + graph[node][i].second;
			if (cost < d[graph[node][i].first]) {
				d[graph[node][i].first] = cost;
				pq.push({ cost, graph[node][i].first });
			}
		}
	}
}

int main() {
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++) {
		// a->b, cost = c
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	fill(d, d + 30001, INF);

	Dijstra(c);

	// 접근 가능한 거리 중 최대 거리 찾기
	int max = -1;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] != INF) {
			count++;
			if (max < d[i]) 
				max = d[i];
		}
	}

	cout << count << ' ' << max << '\n';

	return 0;
}