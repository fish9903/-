#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int table[100 + 1];

int main() {
	cin >> N;
	vector<int> v1(N);

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v1[i] = x;
	}

	table[0] = v1[0];
	table[1] = std::max(v1[0], v1[1]);
	for (int i = 2; i <= N; i++) {
		// i��° �������� ���� ���� ������ ���� max��
		table[i] = std::max(table[i - 1], table[i - 2] + v1[i]);
	}

	cout << table[N] << endl;

	return 0;
}