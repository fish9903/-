// ī�� �̱� ����(���� �迭 ���� ���� ���ص� ��)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int M, N;
	int result = 0;
	cin >> N >> M;

	
	for (int i = 0; i < N; i++) {
		int min_number = 10001, number;

		for (int j = 0; j < M; j++) {
			cin >> number;
			min_number = min(min_number, number);
		}
		result = max(result, min_number);
	}
	
	cout << result << endl;

	return 0;
}