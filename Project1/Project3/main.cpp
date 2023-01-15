// 카드 뽑기 문제(동적 배열 굳이 생성 안해도 됨)

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