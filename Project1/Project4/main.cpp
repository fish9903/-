#include <iostream>

using namespace std;

int main() {
	int N, K;
	int result = 0;
	cin >> N >> K;

	while (N != 1) {
		if (N % K == 0) {
			N /= K;
			result++;
		}
		else {
			N -= 1;
			result++;
		}
	}	

	cout << result << endl;

	return 0;
}