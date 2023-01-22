#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int parent[100000 + 1];
vector<pair<int, pair<int, int>>> graph;

int findParent(int x) {
	if (parent[x] == x) return parent[x];
	else parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph.push_back({ c, {a, b,} }); // a---c--->b
	}

	sort(graph.begin(), graph.end());

	int result = 0;
	int max = -1;
	for (int i = 0; i < graph.size(); i++) {
		int a = graph[i].second.first;
		int b = graph[i].second.second;
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			int cost = graph[i].first;
			result += cost;
			
			if (max < cost) {
				max = cost;
			}
		}
	}

	result -= max;

	cout << result << endl;

	return 0;
}