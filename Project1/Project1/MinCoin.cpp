/*
   주어진 금액 N을 최소한 적은 개수의 동전으로 만드는 것
*/

#include <iostream>

using namespace std;

int main(){
	int N;
	int count = 0;
	int coin_t[4] = { 500, 100, 50, 10 };

	cin >> N;
	
	for (int i = 0; i < 4; i++) {
		count += N / coin_t[i];
		N = N % coin_t[i];
	}

	cout << count << endl;

	return 0;
}