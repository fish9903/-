// 아래에서 부터 채워나가는 방법

#include <iostream>

using namespace std;

int table[30000 + 1] = { 0, };
int X;

int _min(int a, int b, int c, int d) {
	int m = a;
	if (b < m) m = b;
	if (c < m) m = c;
	if (d < m) m = d;
	return m;
}

int main() {
	cin >> X;

	for (int i = 2; i <= X; i++) {
		int min = 0;
		int a, b = 1e9, c = 1e9, d = 1e9;

		// -1
		a = table[i - 1];

		// /2
		if (i % 2 == 0) {
			b = table[i / 2];
		}

		// /3
		if (i % 3 == 0) {
			c = table[i / 3];
		}

		// /5
		if (i % 5 == 0) {
			d = table[i / 5];
		}

		table[i] = _min(a, b, c, d) + 1; // '+1'은 횟수 증가 위해
	}

	cout << table[X] << endl;

	return 0;
}