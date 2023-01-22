#include <iostream>

using namespace std;

int n, m;
int parent[100000 + 1];

int findParent(int x) {
	if (parent[x] == x) return parent[x];
	else parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			// 합치기 연산
			unionParent(b, c);
		}
		else {
			// 판단 연산
			if (findParent(b) == findParent(c)) {
				cout << "yes" << '\n';
			}
			else {
				cout << "no" << '\n';
			}
		}
	}

	return 0;
}