#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int building[50] = { 0, };
//int answer[50] = { 0, };

double Gradient(pair<double, double> x, pair<double, double> y) {
	return (x.second - y.second) / (x.first - y.first);
}

int main() {
	cin >> N;
	int i, j;
	//if (N == 1 || N == 2) return N - 1;

	for (i = 0; i < N; i++) {
		cin >> building[i];
	}

	vector<int> answer(N);
	for (i = 0; i < N - 1; i++) {
		double max_d = -1e9;

		for (j = i + 1; j < N; j++) {
			double g = Gradient({ i,building[i] }, { j,building[j] });
			if (max_d < g) {
				max_d = g;

				// 내가 볼 수 있으면 너도 볼 수 있음
				answer[i]++;
				answer[j]++;
			}
		}
	}

	int Max = *max_element(begin(answer), end(answer));
	cout << Max;

	return 0;
}