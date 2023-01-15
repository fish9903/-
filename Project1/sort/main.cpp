#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void SelectionSort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = arr[j];
			}
		}
		swap(arr[i], arr[min]);
	}
}

void InsertionSort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j >= 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
			}
		}
	}
}

void QuickSort(int* arr, int start, int end) {
	if (start >= end) return;
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {
		while (left <= end && arr[left] <= arr[pivot]) left++; // pivot보다 큰 원소 찾기
		while (right > start && arr[right] >= arr[pivot]) right--; // pivot보다 작은 원소 찾기
		if (left > right) swap(arr[pivot], arr[right]);
		else swap(arr[left], arr[right]);
	}

	QuickSort(arr, start, right - 1);
	QuickSort(arr, right + 1, end);
}

void CountSort(int* arr, int size) {
	int* count = new int[size];
	for (int i = 0; i < size; i++) {
		count[i] = 0;
	}
	
	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << i << ' ';
		}
	}
	cout << endl;

	delete[] count;
}

// pari sorting
bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second < b.second) return true;
	else return false;
}


int main() {
	//int arr[10] = { 4, 2, 1, 9, 5, 3, 7, 8, 6, 10 };
	//int arr2[10] = { 1, 1, 2, 7, 7, 7, 4, 5, 5, 1 };

	////SelectionSort(arr, sizeof(arr)/sizeof(int));
	////InsertionSort(arr, sizeof(arr) / sizeof(int));
	//QuickSort(arr, 0, 9);
	//for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
	//	cout << arr[i] << ' ';
	//}
	//cout << endl;

	//CountSort(arr2, sizeof(arr2) / sizeof(int));

	// -------------
	// reverse
	/*int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v[i] = x;
	}

	sort(v.rbegin(), v.rend());

	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;*/
	

	// pair sorting
	int N;
	cin >> N;
	vector<pair<string, int>> v(N);

	for (int i = 0; i < N; i++) {
		string name;
		int score;
		cin >> name >> score;
		v[i] = { name, score };
	}
	
	sort(v.begin(), v.end(), cmp);

	vector<pair<string, int>>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << (*iter).second << ' ';
	}
	cout << endl;

	return 0;
}