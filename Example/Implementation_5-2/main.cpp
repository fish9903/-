#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int N, K, L; // 크기, 사과, 변환
/*
* -1 = 벽
* 1 = 사과
* 2 = 뱀 몸통(머리, 꼬리 포함)
*/

int t = 0; // time
char direction_list[4] = { 'R', 'D', 'L', 'U' }; // 회전 고려하여 순서
int head_direction = 0; // R
int head_x = 1, head_y = 1;
int tail_x = 1, tail_y = 1;
queue<pair<int, int>> snake; // 뱀 몸 좌표 저장, 맨 처음이 꼬리, 맨 끝이 머리


bool MoveAndHit(vector<vector<int>>& board) {
	// head 전진
	if (head_direction == 0) head_y++;		// right
	else if (head_direction == 1) head_x++; // down
	else if (head_direction == 2) head_y--; // left
	else head_x--;							// up

	if (board[head_x][head_y] == -2 || board[head_x][head_y] == 2) { // hit
		return true;
	}

	snake.push({ head_x, head_y });
	if (board[head_x][head_y] != 1) { // 사과 못 먹음, 꼬리 update
		pair<int, int> p = snake.front();
		board[p.first][p.second] = 0;
		snake.pop();
	}

	board[head_x][head_y] = 2;

	return false;
}

int main() {
	int result;

	cin >> N;
	vector<vector<int>> board(N + 2, vector<int>(N + 2, -2)); // N+2 * N+2
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j] = 0; // 빈 공간
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y; // 행, 열
		cin >> x >> y;
		board[x][y] = 1;
	}
	board[head_x][head_y] = 2;
	board[tail_x][tail_y] = 2;
	snake.push({ head_x, head_y }); // 처음은 꼬리와 몸 좌표 동일

	cin >> L;
	unordered_map<int, char> um; // <time, direction>
	for (int i = 0; i < L; i++) {
		int t; char d; // time, direction
		cin >> t >> d;
		um.insert({ t,d });
	}

	while (1) {
		// 방향 정하기
		if (um.find(t) != um.end()) { // time 찾으면 head direction 갱신
			// L: 왼쪽 90도, D: 오른쪽 90도
			if (um[t] == 'D')
				head_direction = (head_direction + 1) % 4;
			else
				head_direction = (head_direction - 1 + 4) % 4;
		}

		//for (int i = 0; i < N + 2; i++) {
		//	for (int j = 0; j < N + 2; j++) {	
		//		cout << board[i][j] << "\t";
		//	}
		//cout << endl;
		//}
		//cout << endl;

		if (MoveAndHit(board)) { // hit
			t++;
			result = t;
			break;
		}
		t++;
	}

	cout << result << endl;

	return 0;
}