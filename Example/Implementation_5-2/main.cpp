#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int N, K, L; // ũ��, ���, ��ȯ
/*
* -1 = ��
* 1 = ���
* 2 = �� ����(�Ӹ�, ���� ����)
*/

int t = 0; // time
char direction_list[4] = { 'R', 'D', 'L', 'U' }; // ȸ�� ����Ͽ� ����
int head_direction = 0; // R
int head_x = 1, head_y = 1;
int tail_x = 1, tail_y = 1;
queue<pair<int, int>> snake; // �� �� ��ǥ ����, �� ó���� ����, �� ���� �Ӹ�


bool MoveAndHit(vector<vector<int>>& board) {
	// head ����
	if (head_direction == 0) head_y++;		// right
	else if (head_direction == 1) head_x++; // down
	else if (head_direction == 2) head_y--; // left
	else head_x--;							// up

	if (board[head_x][head_y] == -2 || board[head_x][head_y] == 2) { // hit
		return true;
	}

	snake.push({ head_x, head_y });
	if (board[head_x][head_y] != 1) { // ��� �� ����, ���� update
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
			board[i][j] = 0; // �� ����
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y; // ��, ��
		cin >> x >> y;
		board[x][y] = 1;
	}
	board[head_x][head_y] = 2;
	board[tail_x][tail_y] = 2;
	snake.push({ head_x, head_y }); // ó���� ������ �� ��ǥ ����

	cin >> L;
	unordered_map<int, char> um; // <time, direction>
	for (int i = 0; i < L; i++) {
		int t; char d; // time, direction
		cin >> t >> d;
		um.insert({ t,d });
	}

	while (1) {
		// ���� ���ϱ�
		if (um.find(t) != um.end()) { // time ã���� head direction ����
			// L: ���� 90��, D: ������ 90��
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