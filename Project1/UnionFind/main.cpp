#include <iostream>

using namespace std;

int v, e;
int parent[10000 + 1]; // parent 정보 저장

// parent 찾기
int FindParent(int* parent, int x) {
	if (parent[x] != x) parent[x] = FindParent(parent, parent[x]);
	return parent[x]; // 하나의 최상 부모와 연결, x로 반환하면 바로 윗단계 부모와 연결
}

// 집합 합치기
void UnionParent(int a, int b) {
	int a_p = FindParent(parent, a);
	int b_p = FindParent(parent, b);
	if (a_p < b_p) parent[b] = a;
	else parent[a] = b;
}

int main(void) {
    cin >> v >> e;

    // 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // Union 연산을 각각 수행
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        UnionParent(a, b);
    }

    // 각 원소가 속한 집합 출력하기
    cout << "각 원소가 속한 집합: ";
    for (int i = 1; i <= v; i++) {
        cout << FindParent(parent, i) << ' ';
    }
    cout << '\n';

    // 부모 테이블 내용 출력하기
    cout << "부모 테이블: ";
    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}