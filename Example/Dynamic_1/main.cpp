#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>


using namespace std;

int T, n, m;
int board[22][22];

int Max(int a, int b, int c) {
	int result = a;
	if (result < b) result = b;
	if (result < c) result = c;
	return result;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> T;
	int i, j;
	while (T--) {
		int result = 0;
		cin >> n >> m;
		fill(&board[0][0], &board[21][22], 0);
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				cin >> board[i][j];
			}
		}

		for (i = 2; i <= m; i++) {
			for (j = 1; j <= n; j++) {
				board[j][i] += Max(board[j - 1][i - 1], board[j][i - 1], board[j + 1][i - 1]);
				if (i == m) {
					result = max(result, board[j][i]);
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << board[i][j] << "   ";
			}
			cout << endl;
		}

		cout << result << '\n';
	}
	

	return 0;
}