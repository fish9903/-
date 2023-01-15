#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, M, result = 0;

void dfs(int** graph, int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= M) {
		return;
	}
	
	if (graph[i][j] == 0) {
		graph[i][j] = 1;

		// 상하좌우 방문
		dfs(graph, i - 1, j);
		dfs(graph, i, j - 1);
		dfs(graph, i + 1, j);
		dfs(graph, i, j + 1);
	}
}

int main() {
	cin >> N >> M;

	int** graph = new int* [N];
	for (int i = 0; i < N; i++) {
		graph[i] = new int[M];
	}

	// 1문자씩 입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				dfs(graph, i, j);
				result++;
			}
		}
	}	

	cout << result << endl;

	for (int i = 0; i < N; i++)
		delete[] graph[i];
	delete[] graph;

	return 0;
}