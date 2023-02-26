#include <iostream>
#include <map>
#include <set>
#include <tuple>

using namespace std;

int main() {
	map<int, int> m;
	set<int> s;
	tuple<int, int, int, int> tt[10];
	for (int i = 0; i < 10; i++) {
		tt[i] = make_tuple(1, 2, 3, 4);
	}
	
	return 0;
}