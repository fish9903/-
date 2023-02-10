/*
* 현재 상황에서 가장 좋아보이는 것만을 선택하는 알고리즘
* 그럴싸한 답 도출가능, 최선은 보장 못함
* ex) 다익스트라, 크루스칼 알고리즘
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;
int result = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	// 오름차순 정렬
	sort(v.begin(), v.end());
	
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		count++;
		if (count >= v[i]) {
			result++;
			count = 0;
		}		
	}

	cout << result << endl;

	return 0;
}