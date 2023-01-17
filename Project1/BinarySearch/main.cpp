#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// recursion
int BinarySearch1(int* arr, int start, int end, int target) {
	if (start > end) return NULL;
	
	int mid = (start + end) / 2;

	if (arr[mid] == target) return mid;
	else if (arr[mid] < target) BinarySearch1(arr, mid + 1, end, target);
	else BinarySearch1(arr, start, mid - 1, target);
}

// for
int BinarySearch2(int* arr, int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == target) return mid;
		else if (arr[mid] < target) start = mid + 1;
		else end = mid - 1;
	}
	return NULL;
}

int main() {
	int N;
	int arr[10] = { 1,2,3,4,5,6,7,8,10,14 };
	int arr2[10];
	cin >> N;

	cout << BinarySearch2(arr, 0, 9, N);

	return 0;
}