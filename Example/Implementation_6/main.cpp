#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M; // M: ��ǥ ġŲ�� ��
int chicken = 0; // ���� ġŲ �� ��
int house = 0; // ���� �� ��

// �Ÿ� ���
int Distance(vector<pair<int, int>> house_list, vector<pair<int, int>> candidate) {
	int sum = 0;
	for (int i = 0; i < house; i++) {
		int m = 1e9;
		for (int j = 0; j < candidate.size(); j++) {
			int d = abs(house_list[i].first - candidate[j].first) + abs(house_list[i].second - candidate[j].second);
			m = min(m, d);
		}
		sum += m;
	}
	return sum;
}

int main() {
	//int result = 1e9;

	//cin >> N >> M;
	//vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));

	//// row, col
	//vector<pair<int, int>> house_list;
	//vector<pair<int, int>> chicken_list;

	//// �ʱ�ȭ
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		int x;
	//		cin >> x;
	//		board[i][j] = x;

	//		if (x == 1) {
	//			house++;
	//			house_list.push_back({ i, j });
	//		}
	//		else if (x == 2) {
	//			chicken++;
	//			chicken_list.push_back({ i, j });
	//		}
	//	}
	//}

	//// ��� ��ų ġŲ�� ����
	//vector<int> choose(chicken, 0);
	//fill(choose.end() - M, choose.end(), 1); // ������ M���� 1�� ����(M�� ����)

	//do {
	//	vector<pair<int, int>> candidate;
	//	for (int i = 0; i < chicken; i++) {
	//		if (choose[i] == 1) { // ���õ� ���̸�
	//			candidate.push_back(chicken_list[i]);
	//		}
	//	}
	//	
	//	// �ּ� ������ �Ÿ� ���
	//	result = min(result, Distance(house_list, candidate));
	//} while (next_permutation(choose.begin(), choose.end()));

	//cout << result << endl;

	string s = "1234";
	int i = (s[0] - '0');

	cout << i << endl;

	return 0;
}