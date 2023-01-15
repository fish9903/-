#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

int main() {
	cin >> N >> K;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		A[i] = x;
	}
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		B[i] = x;
	}

	// sort(A�� ��������, B�� ��������)
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());

	// A, B K�� ��ȯ
	for (int i = 0; i < K; i++) {
		swap(A[i], B[i]);
	}

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i];
	}
	cout << sum << endl;

	return 0;
}