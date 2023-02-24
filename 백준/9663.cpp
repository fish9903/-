#include <iostream>
#include <vector>

using namespace std;

int N;
int board[100000];
//int flag = 0;
int answer;

bool Valid(int depth) {
	for (int i = 0; i < depth; i++) {
		if (board[depth] == board[i] || depth == i || abs(board[depth] - board[i]) == abs(depth - i)) {
			return false;
		}
	}
	return true;
}

void BackTracking(int depth, int n) {
	if (depth == n) {
		/*for (int i = 0; i < N; i++) {
			cout << board[i] + 1<< '\n';
		}
		flag = 1;*/
		answer++;
		return;
	}

	for (int i = 0; i < n; i++) {
		//if (flag == 1) break;
		board[depth] = i;
		if (Valid(depth)) {
			BackTracking(depth + 1, n);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	BackTracking(0, N);
	cout << answer << '\n';

	return 0;
}