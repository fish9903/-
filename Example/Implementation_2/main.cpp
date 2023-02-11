#include <iostream>
#include <algorithm>

using namespace std;

string s;

int main() {
	cin >> s;

	sort(s.begin(), s.end());

	int sum = 0;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9') {
			sum += s[i] - '0';
			count++;
		}
		else 
			break;
	}

	s.replace(0, count, "");
	
	cout << s << sum << endl;

	return 0;
}