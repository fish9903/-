#include <iostream>
#include <vector>

using namespace std;

string s;
vector<int> v;
int result = 0;

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i] - '0');
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0 || v[i] == 1 || result == 0 || result == 1) result += v[i];
		else result *= v[i];
	}

	cout << result << endl;

	return 0;
}