#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> house;
int result;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> C;
	int i;
	for (i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		house.push_back(temp);
	}
	sort(house.begin(), house.end());

	// �Ÿ� ���� ����, ��, �߰� ����
	// start = �ּ� �Ÿ�
	// end = �ִ� �Ÿ�
	int start = 1;
	int end = house[N - 1] - house[0];
	while (start <= end) {
		int mid = (start + end) / 2;

		// ��ġ ����
		int cnt = 1;
		int prev = house[0];
		for (i = 1; i < N; i++) {
			// �Ÿ� �����ϸ� ��ġ
			if (house[i] - prev >= mid) {
				prev = house[i];
				cnt++;
			}
		}

		// �Ÿ��� mid�� �� ���������Ƿ� �ּ� �Ÿ��� mid+1�� ����
		if (cnt >= C) {
			start = mid + 1;
			result = max(result, mid);
		}
		else {
			end = mid - 1;
		}
	}
	cout << result;

	return 0;
}