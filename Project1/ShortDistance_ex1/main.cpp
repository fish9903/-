#include <iostream>

#define INF 1e9

using namespace std;

int n, m;
int x, k;
int graph[100 + 1][100 + 1];

int main() {
	cin >> n >> m;
	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
	}

	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = std::min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	cin >> x >> k;
	int result = graph[1][k] + graph[k][x];

	if (result >= INF) cout << -1 << endl;
	else cout << result << '\n';

	return 0;
}