#include <iostream>
#include <vector>

using namespace std;

int N, x;
int cnt; // if cnt = 0 return -1
vector<int> v;

int main() {
	cin >> N >> x;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	// find lower, upper bound
	int low = lower_bound(v.begin(), v.end(), x) - v.begin();	// x�̻��� ���� ó�� �����ϴ� ��ġ ��ȯ
	int high = upper_bound(v.begin(), v.end(), x) - v.begin();	// x�� �ʰ��ϴ� ù ��ġ ��ȯ
	cnt = high - low;
	if (cnt == 0) cout << -1 << endl;
	else cout << high - low << endl;

	return 0;
}