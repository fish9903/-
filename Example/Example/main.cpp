/*
* ���� ��Ȳ���� ���� ���ƺ��̴� �͸��� �����ϴ� �˰���
* �׷����� �� ���Ⱑ��, �ּ��� ���� ����
* ex) ���ͽ�Ʈ��, ũ�罺Į �˰���
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

	// �������� ����
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