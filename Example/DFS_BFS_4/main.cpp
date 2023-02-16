#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> Data;
int ADD, SUB, MUL, DIV;
int maxSum = -1e9;
int minSum = 1e9;

void dfs(int i, int sum) {
	if (i == N) {
		maxSum = max(maxSum, sum);
		minSum = min(minSum, sum);
		return;
	}

	if (ADD > 0) {
		int cal = sum + Data[i];
		ADD--;
		dfs(i + 1, cal);
		ADD++;
	}
	if (SUB > 0) {
		int cal = sum - Data[i];
		SUB--;
		dfs(i + 1, cal);
		SUB++;
	}
	if (MUL > 0) {
		int cal = sum * Data[i];
		MUL--;
		dfs(i + 1, cal);
		MUL++;
	}
	if (DIV > 0) {
		int cal = sum / Data[i];
		DIV--;
		dfs(i + 1, cal);
		DIV++;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		Data.push_back(x);
	}
	cin >> ADD >> SUB >> MUL >> DIV;

	// dfs
	// √ ±‚ sum = Data[0]
	dfs(1, Data[0]);

	cout << maxSum << '\n' << minSum << '\n';

	return 0;
}