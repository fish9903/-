#include <iostream>


using namespace std;

string s;

int main() {
	cin >> s;

	int left = 0;
	int right = 0;
	for (int i = 0; i < s.size() / 2; i++) {
		left += s[i];
		right += s[i + s.size() / 2];
	}

	if (left == right) cout << "LUCKY" << endl;
	else cout << "READY" << endl;
	

	return 0;
}