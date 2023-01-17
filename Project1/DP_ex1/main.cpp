#include <iostream>

using namespace std;

long long d[100] = { 0, };

// recursion
int fib(int n) {
	if (n == 1 || n == 2) return 1;

	if (d[n] != 0) return d[n];

	d[n] = fib(n - 1) + fib(n - 2);

	return d[n];
}

// for
int fib2(int n) {
	d[1] = 1, d[2] = 1;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	return d[n];
}

int main() {
	int N;
	cin >> N;

	cout << fib(N) << endl;
	cout << fib2(N) << endl;

	return 0;
}