#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

int main() {
	cin >> s;
	int answer = s.size();
	
	for (int i = 1; i <= s.size() / 2; i++) { // i: pattern size
		string pattern = "";
		string compressed = "";
		pattern = s.substr(0, i);
		int count = 1;
		for (int j = i; j < s.size(); j += i) {
			string div = s.substr(j, i);
			if (div == pattern) {
				count++;
			}
			else {
				if (count >= 2) compressed += to_string(count) + pattern;
				else compressed += pattern;
				count = 1;
				pattern = s.substr(j, i);
			}
		}
		if (count >= 2) compressed += to_string(count) + pattern;
		else compressed += pattern;
		//cout << compressed << endl;
		answer = std::min(answer, (int)compressed.size());
	}
	
	cout << answer << endl;

	return 0;
}