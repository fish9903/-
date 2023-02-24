#include <iostream>
#include <vector>

using namespace std;

int N, M;
int truth_n;
vector<int> party[52];
vector<int> truth_p;
int truth[52] = { 0, }; // 1: 진실을 아는 혹은 알게될 사람
int parent[52];
int answer;

int findParent(int a) {
	if (parent[a] != a) {
		parent[a] = findParent(parent[a]);
	}
	return parent[a];
}

bool merge(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return false;
	parent[b] = a;
	return true;
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

int main() {
	cin >> N >> M;
	init();
	cin >> truth_n;
	for (int i = 0; i < truth_n; i++) {
		int p;
		cin >> p;
		truth_p.push_back(p);
		truth[p] = 1;
	}

	for (int i = 0; i < M; i++) {
		int party_n; // i번호의 파티에 참석하는 사람 수
		cin >> party_n;
		int temp; // merge 대상(첫 번째 원소)
		for (int j = 0; j < party_n; j++) {
			int person;
			cin >> person;
			party[i].push_back(person);
			if (j == 0) {
				temp = person;
			}
			else {
				merge(temp, person);
			}
		}
	}

	/*for (int i = 1; i <= N; i++)
		cout << parent[i] << " ";
	cout << endl;*/

	for (int i = 1; i <= N; i++) {
		int p1 = findParent(i);
		for (int j = 0; j < truth_n; j++) {
			int p2 = findParent(truth_p[j]);
			if (p1 == p2)
				truth[i] = 1;
		}
	}

	/*for (int i = 1; i <= N; i++)
		cout << truth[i] << " ";
	cout << endl;*/

	for (int i = 0; i < M; i++) {
		int flag = 1;
		for (int j = 0; j < party[i].size(); j++) {
			if (truth[party[i][j]] == 1) {
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			answer++;
	}

	cout << answer << '\n';

	return 0;
}