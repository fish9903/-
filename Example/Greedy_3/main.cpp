#include <iostream>

using namespace std;

string s;
int result = 0;

int main() {
	cin >> s;

	string new_s = "";

	for (int i = 1; i < s.size(); i++) {
		new_s += s[i - 1];
		while (s[i - 1] == s[i]) {
			i++;
		}
	}
	if (s[s.size() - 1] != new_s[new_s.size() - 1]) {
		new_s += s[s.size() - 1];
	}

	int zero = 0;
	int one = 0;
	for (int i = 0; i < new_s.size(); i++) {
		if (new_s[i] == '0') zero++;
		else one++;
	}
	
	result = (zero < one) ? zero : one;
	cout << result << endl;

	return 0;
}