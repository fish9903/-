// 왕실의 나이트 문제
// 가능한 움직임을 기록해두고 이를 이용

#include <iostream>

using namespace std;

int main() {
	string pos;
	int count = 0;
	cin >> pos;

	int x, y;
	x = pos[0] - 'a' + 1;
	y = pos[1] - '0';

	int double_move[2] = { 2,-2 };
	int once_move[2] = { 1,-1 };

	for (int i = 0; i < 2; i++) {
		int x_pos = x + double_move[i];
		for (int j = 0; j < 2; j++) {
			int y_pos = y + once_move[j];

			if (x_pos <= 8 && x_pos >= 1 && y_pos <= 8 && y_pos >= 1) {
				count++;
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		int x_pos = x + once_move[i];
		for (int j = 0; j < 2; j++) {
			int y_pos = y + double_move[j];

			if (x_pos <= 8 && x_pos >= 1 && y_pos <= 8 && y_pos >= 1) {
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}