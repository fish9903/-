#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>

using namespace std;

int N; // 1~15
int dp[17] = { 0, };
vector<pii> Data(17); // Data[1] = {time, cost}, ...

int main() {
	freopen("input.txt", "r", stdin);
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) {
		int t, c;
		cin >> t >> c;
		Data[i] = { t, c };
	}

	// update dp
	for (i = N; i >= 1; i--) {
		if (Data[i].first <= N - i + 1) {
			int Max = *max_element(dp + i + Data[i].first, dp + N + 1);
			dp[i] = Max + Data[i].second;
		}
	}

	int result = *max_element(begin(dp), end(dp));
	cout << result << '\n';

	return 0;
}