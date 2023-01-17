#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 찾으면 1, 아니면 0 반환
int BinarySearch(vector<int> arr, int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == target) return 1;
		else if (arr[mid] < target) start = mid + 1;
		else end = mid - 1;
	}
	return 0;
}

int main() {
	int N, M;

	cin >> N;
	vector<int> v1(N);
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v1[i] = x;
	}
	sort(v1.begin(), v1.end());

	cin >> M;
	vector<int> v2(M);
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		v2[i] = x;
	}

	for (int i = 0; i < M; i++) {
		int result = BinarySearch(v1, 0, N - 1, v2[i]);
		if (result) cout << "yes";
		else cout << "no";
		cout << ' ';
	}
	cout << endl;

	return 0;
}