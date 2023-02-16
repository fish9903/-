#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAXN 300001

using namespace std;

vector<int> board[MAXN];
vector<int> d(MAXN, -1); // X에서 index까지 거리 저장
vector<int> result;

// 도시 개수, 도로 개수, 목표 거리 정보, 출발 도시
int N, M, K, X;

int main() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int start, dest;
		cin >> start >> dest;
		board[start].push_back(dest); // start --> dest 생성
	}

	d[X] = 0;

	// BFS
	queue<int> q;
	q.push(X);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i: board[now]) {
			int nextCity = board[now][i];
			if (d[nextCity] == -1) {
				d[nextCity] = d[now] + 1;
				if (d[nextCity] == K)
					result.push_back(nextCity);
				q.push(nextCity);
			}
		}
	}

	if (result.empty()) cout << -1 << endl;
	else {
		sort(result.begin(), result.end());
		for(int i: result)
			cout << i << ' ';
		cout << endl;
	}

	return 0;
}