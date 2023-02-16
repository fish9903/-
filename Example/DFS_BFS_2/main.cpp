#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define p pair<int, int>

using namespace std;

int N, M; // 세로, 가로

// R, D, L, U
int move_r[4] = { 0, 1, 0, -1 };
int move_c[4] = { 1, 0, -1, 0 };

int main() {
	int maxSafe = 0;

	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));
	queue<p> q; // 바이러스 좌표
	vector<p> candidate; // 벽 후보
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x;
			cin >> x;
			board[i][j] = x;

			if (x == 2)	q.push({ i ,j });
			else if (x == 0) candidate.push_back({ i, j });
		}
	}

	vector<int> candidate_index(candidate.size(), 0);
	vector<p> wall;
	fill(candidate_index.end() - 3, candidate_index.end(), 1);
	do {
		int result = 0;

		vector<vector<int>> board_temp = board;
		for (int i = 0; i < candidate.size(); i++) {
			if (candidate_index[i] == 1) {
				wall.push_back({ candidate[i].first, candidate[i].second });
				board_temp[candidate[i].first][candidate[i].second] = 1;
			}
		}

		queue<p> q_temp = q;
		while (!q_temp.empty()) {
			int r = q_temp.front().first;
			int c = q_temp.front().second;
				q_temp.pop();

			for (int i = 0; i < 4; i++) {
				int next_r = r + move_r[i];
				int next_c = c + move_c[i];

				if (next_r < N && next_r >= 0 && next_c < M && next_c >= 0) {
					if (board_temp[next_r][next_c] == 0) {
						q_temp.push({ next_r, next_c });
						board_temp[next_r][next_c] = 2;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board_temp[i][j] == 0) result++;
				//cout << board_temp[i][j] << ' ';
			}
			//cout << endl;
		}
		//cout << endl;

		maxSafe = max(maxSafe, result);

		/*for (int i = 0; i < wall.size(); i++) {
			board[wall[i].first][wall[i].second] = 0;
		}*/
	} while (next_permutation(candidate_index.begin(), candidate_index.end()));

	cout << maxSafe;

	return 0;
}