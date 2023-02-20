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

	// 거리 기준 시작, 끝, 중간 설정
	// start = 최소 거리
	// end = 최대 거리
	int start = 1;
	int end = house[N - 1] - house[0];
	while (start <= end) {
		int mid = (start + end) / 2;

		// 설치 개수
		int cnt = 1;
		int prev = house[0];
		for (i = 1; i < N; i++) {
			// 거리 만족하면 설치
			if (house[i] - prev >= mid) {
				prev = house[i];
				cnt++;
			}
		}

		// 거리가 mid일 때 가능헀으므로 최소 거리를 mid+1로 증가
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