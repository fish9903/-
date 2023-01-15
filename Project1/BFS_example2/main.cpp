#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int result = 1;

// 상 하 좌 우 (행, 열)
int dr[] = { -1, 1, 0 ,0 };
int dc[] = { 0, 0, -1, 1 };

void bfs(int** graph, int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_r = x + dr[i];
			int next_c = y + dc[i];

			if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) continue;
			else if (next_r == 0 && next_c == 0) continue;
			else if (graph[next_r][next_c] == 0) continue;
			else if (graph[next_r][next_c] == 1) {
				graph[next_r][next_c] = graph[x][y] + 1;
				q.push({ next_r, next_c });
			}
		}
	}
}

int main() {
	cin >> N >> M;

	int** graph = new int* [N];
	for (int i = 0; i < N; i++)
		graph[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}


	bfs(graph, 0, 0);

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << graph[i][j];
	//	}
	//	cout << endl;
	//}

	result = graph[N - 1][M - 1];
	cout << result << endl;

	for (int i = 0; i < N; i++)
		delete[] graph[i];
	delete graph;

	return 0;
}