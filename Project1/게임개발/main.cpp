// 꼭 동적 배열로 x(크키가 정해져 있는 경우라면)
// 이동 방법이 정해져있다면 이를 배열로 정보를 저장해두고 이용하는 것이 좋음
// 특정 동작이 반복되면 함수로 추출하기

#include <iostream>

using namespace std;

int count = 1;
int N, M;
int x, y, head; // start position

// 실제 움직이는 동작
// 북 동 남 서
// 0  1  2  3
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

void TurnLeft() {
	head -= 1;
	if (head == -1) head = 3;
}

int main() {
	cin >> N >> M;
	
	cin >> x >> y >> head;

	// allocate
	int** board = new int* [N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[M];
	}

	// 2D array
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;
			board[i][j] = n;
		}
	}
	board[x][y] = 2; // 시작 지점을 가본 곳으로 설정

	int turn = 0;
	while (1) {
		TurnLeft();
		int next_x = x + dx[head];
		int next_y = y + dy[head];
		if (board[next_x][next_y] == 0) {
			x = next_x;
			y = next_y;
			board[next_x][next_y] = 2;

			turn = 0;
			::count++;

			continue;
		}
		else {
			turn++;
		}

		if (turn == 4) {
			next_x = x - dx[head];
			next_y = y - dy[head];

			if (board[next_x][next_y] == 1) {
				break;
			}
			
			x = next_x;
			y = next_y;
			turn = 0;
		}
	}

	cout << ::count << endl;

	// free
	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;

	return 0;
}