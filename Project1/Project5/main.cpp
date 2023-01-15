#include <iostream>

using namespace std;

int main() {
	int N; // size
	char move;
	int x = 1, y = 1;

	cin >> N;
	cin >> move;
	while (move != '\n') {
		switch (move) {
		case 'U':
			if (x != 1) {
				x--;
			}
			break;
		case 'D':
			if (x != N) {
				x++;
			}
			break;
		case 'L':
			if (y != 1) {
				y--;
			}
			break;
		case 'R':
			if (y != N) {
				y++;
			}
			break;
		default:
			break;
		}

		// 공백 무시하고 enter만 받을 경우
		move = cin.get();
	}

	cout << x << " " << y << endl;

	return 0;
}