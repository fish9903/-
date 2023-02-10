#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int result = 0;

int main() {
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v[i] = x;
	}
	sort(v.begin(), v.end());

	int target = 1;
	for (int i = 0; i < v.size(); i++) {
		if (target < v[i])
			break;
		target += v[i];
	}

	result = target;

	cout << result << endl;

	return 0;
}