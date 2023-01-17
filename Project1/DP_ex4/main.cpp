#include <iostream>

using namespace std;

int table[1000 + 1];

// a(n) = a(n-1) + 2*a(n-2)
int main() {
	int N;
	cin >> N;

	table[1] = 1;
	table[2] = 3;
	for (int i = 3; i <= N; i++) {
		table[i] = (table[i - 1] + 2 * table[i - 2]) % 796796;
	}

	cout << table[N] << endl;

	return 0;
}