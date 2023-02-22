#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int n;
long long board[MAX+1][MAX+1];

int main() {
	freopen("input.txt", "r", stdin);
	fill(begin(board[0]), end(board[MAX]), 0);
	cin >> n;
	int i, j;
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			cin >> board[i][j];
		}
	}

	// dp
	long long result = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			board[i][j] += max(board[i - 1][j], board[i - 1][j - 1]);
			if (i == n) {
				//result = max(result, board[i][j]);
			}
		}
	}

	//sort(begin(board[n]), end(board[n]));
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= MAX; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	result = *max_element(begin(board[n]), end(board[n]));

	cout << result << '\n';

	return 0;
}