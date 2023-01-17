#include <iostream>
#include <vector>

using namespace std;

int t[10000 + 1];
int N, M;

int main() {
	fill_n(t, 10001, 10001);
	t[0] = 0;

	cin >> N >> M;
	vector<int> v(N); // 화폐 단위 저장
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v[i] = x;
	}

	for (int i = 0; i < N; i++) {
		for (int j = v[i]; j <= M; j++) {
			t[j] = std::min(t[j], t[j - v[i]] + 1);
		}
	}

	if (t[M] == 10001) cout << -1 << endl;
	else cout << t[M] << endl;

	return 0;
}