#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
int answer = -1;

// binary search
void bs(int s, int e) {
	if (s > e) 
		return;

	int mid = (s + e) / 2;
	if (v[mid] == mid) {
		answer = mid;
		return;
	}
	else if (v[mid] < mid) {
		bs(mid + 1, e);
	}
	else {
		bs(s, mid - 1);
	}
}

void bs2(int s, int e) {
	while (s <= e) {
		int mid = (s + e) / 2;
		if (v[mid] == mid) {
			answer = mid;
			return;
		}
		else if (v[mid] < mid) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	// search
	bs2(0, N - 1);
	
	cout << answer << endl;

	return 0;
}