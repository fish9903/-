#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M; // 개수, 최대 무게
int result = 0;

int main() {
	cin >> N >> M;
	vector<int> v(N);
	
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v[i] = x;
	}
	sort(v.begin(), v.end());

	int count = 1;
	for (int i = 0; i < N - 1; i++) {
		if (v[i] == v[i + 1]) {
			count++;
		}
		else {
			result += count * (v.size() - i - 1);
			count = 1;
		}
	}


	cout << result << endl;

	return 0;
}