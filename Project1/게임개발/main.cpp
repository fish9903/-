// �� ���� �迭�� x(ũŰ�� ������ �ִ� �����)
// �̵� ����� �������ִٸ� �̸� �迭�� ������ �����صΰ� �̿��ϴ� ���� ����
// Ư�� ������ �ݺ��Ǹ� �Լ��� �����ϱ�

#include <iostream>

using namespace std;

int count = 1;
int N, M;
int x, y, head; // start position

// ���� �����̴� ����
// �� �� �� ��
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
	board[x][y] = 2; // ���� ������ ���� ������ ����

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