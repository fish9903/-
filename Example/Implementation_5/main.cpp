#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, K, L; // ũ��, ���, ��ȯ
int head_x, head_y, tail_x, tail_y; // ���� ��ġ
int head_direction;
// char direction_list[4] = { 'R','U','L','D' }; // �ٶ󺸴� ���� ȸ�� ����Ͽ� ���� ���ϱ�
int t = 0;

bool MoveAndHit(char turn, vector<vector<int>>& board) {
	// L: ���� 90��, D; ������ 90��, N�� ����
	if (turn == 'L') {
		if (head_direction == 3) head_direction = 0;
		else head_direction++;
	}
	else if (turn == 'D') {
		if (head_direction == 0) head_direction = 3;
		else head_direction--;
	}

	// R, U, L, D
	if (head_direction == 0) head_y++;
	else if (head_direction == 1) head_x--;
	else if (head_direction == 2) head_y--;
	else if (head_direction == 3) head_x++;

	int next_pos = board[head_x][head_y]; // �ӽ� ����--�߿�!!

	if (next_pos > 0 || next_pos == -2) { // �ε�����
		return true;
	}
	else {
		board[head_x][head_y] = t; // �Ӹ� ������ ����
	}

	if (next_pos != -1) { // ��� ���� �������� ���� ����
		board[tail_x][tail_y] = 0;

		// R, U, L, D
		int x_move[4] = { 0,-1,0,1 };
		int y_move[4] = { 1,0,-1,0 };
		int min = 10001;
		int final_x , final_y;
		for (int i = 0; i < 4; i++) {
			int next_x = tail_x + x_move[i];
			int next_y = tail_y + y_move[i];
			if (board[next_x][next_y] >= 1 && board[next_x][next_y] < min) {
				min = board[next_x][next_y];
				final_x = next_x;
				final_y = next_y;
			}
		}

		tail_x = final_x;
		tail_y = final_y;
	} 

	return false;
}

int main() {
	head_direction = 0; // �Ӹ� ����
	cin >> N;
	vector<vector<int>> board(N + 2, vector<int>(N + 2, -2)); // N+2 x N+2, �� = -2
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			board[i + 1][j + 1] = 0;
	}
	board[1][1] = 1; // �Ӹ�(��)
	head_x = 1;
	head_y = 1;
	tail_x = 1;
	tail_y = 1;

	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = -1; // ���
	}

	cin >> L;
	unordered_map<int, char> m;
	for (int i = 0; i < L; i++) {
		int x;
		char y;
		cin >> x >> y;
		m.insert({ x, y });
	}

	char turn;
	while (1) {
		turn = 'N';
		if (m.find(t) != m.end()) { // find
			turn = m[t];
		}

		//for (int i = 0; i < N + 2; i++) {
		//	for (int j = 0; j < N + 2; j++) {	
		//		cout << board[i][j] << "\t";
		//	}
		//	cout << endl;
		//}
		//cout << endl;

		t++;
		if (MoveAndHit(turn, board)) {
			cout << t << endl;
			break;
			//return t;
		}
	}

	return 0;
}