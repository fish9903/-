#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
	long long ll = 123;
	int a;

	cout << typeid(ll).name() << endl;
	cout << typeid(a).name() << endl;
	return 0;
}