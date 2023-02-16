#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
int S, X, Y;
// R, D, L ,U
int moveX[4] = { 0, 1, 0, -1 }; // dx
int moveY[4] = { 1, 0, -1, 0 }; // dy

class Virus {
public:
	int number;
	int x;
	int y;
	int t;
	Virus(int n, int i, int j, int s)
		:number(n), x(i), y(j), t(s) {}

	bool operator<(Virus& v) {
		return this->number < v.number;
	}
};

int main() {
	cin >> N >> K;
	vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));
	vector<Virus> temp;
	queue<Virus> virus;
	int t; // virus가 추가된 시간
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int x;
			cin >> x;
			board[i][j] = x;
			if (x != 0) {
				temp.push_back(Virus(x, i, j, 0));
			}
		}
	}
	sort(temp.begin(), temp.end());
	for (Virus i : temp) {
		virus.push(i);
	}

	cin >> S >> X >> Y; // S초 후 (X, Y)

	while (!virus.empty()) {
		int t = virus.front().t;
		if (t == S) break;

		t++;
		// bfs
		int virusNum = virus.front().number;
		int nowX = virus.front().x;
		int nowY = virus.front().y;
		virus.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = nowX + moveX[i];
			int nextY = nowY + moveY[i];
			if (nextX <= N && nextX >= 1 && nextY <= N && nextY >= 1) {
				if (board[nextX][nextY] == 0) {
					board[nextX][nextY] = virusNum;
					virus.push(Virus(virusNum, nextX, nextY, t));
				}
			}
		}
	}
	
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++)
	//		cout << board[i][j] << ' ';
	//	cout << endl;
	//}

	cout << board[X][Y] << '\n';

	return 0;
}