#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, count = 0;
	string str;
	cin >> N;

	for (int h = 0; h <= N; h++) {
		for (int m = 0; m < 60; m++) {
			for (int s = 0; s < 60; s++) {
				str = to_string(h) +to_string(m) + to_string(s);
				if (str.find('3') != string::npos) {
					count++;
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}