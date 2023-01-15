// ū ���� ��Ģ

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M, K;
	int result = 0;
	vector<int> v;

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		v.push_back(number);
	}

	sort(v.begin(), v.end(), greater<int>());

	int repeat = 0;
	int max = v[0] * K + v[1];
	int pattern = K + 1;

	if (M == K) {
		result = v[0] * K;
	}
	else {
		repeat = M / pattern;
		result += (repeat * max); // pattern �ݺ� �Ǵ� ��ŭ ����
		result += (M % pattern) * v[0]; // ������ ó��
	}

	cout << result << endl;

	return 0;
}