#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

// ���� �ڸ��� ���� ��(remain)���� Ž���� ����(mid) �����Ѵ�.
int BinarySearch(int* arr, int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;
		int remain = 0;
		for (int i = 0; i < N; i++) {
			if(mid < arr[i])
				remain = remain + arr[i] - mid;
		}

		if (remain == target) return mid;
		else if (remain < target) end = mid - 1;
		else start = mid + 1;
	}
}

int main() {
	cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int max = *std::max_element(arr, (arr + N));

	printf("%d\n", BinarySearch(arr, 0, max, M));
	
	delete[] arr;
	return 0;
}