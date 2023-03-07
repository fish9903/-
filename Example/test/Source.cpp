// union find ���� ������ ��
// 1. parent ���� ������ ��Ȯ�� �� ��
// 2. parent �迭 �ϼ� ��, �̸� ���� ������� ���� findParent(parent[i])�� �ѹ� �� ����� ��

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

set<int> answer;
vector<int> parent;

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

    if (a < b) parent[b] = a;
    else parent[a] = b;
    //parent[b] = a;
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) parent.push_back(i);

    // union find
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && computers[i][j] == 1)
                merge(i, j);
        }
    }

    for (int i = 0; i < n; i++) parent[i] = findParent(parent[i]);

    for (int i = 0; i < n; i++) {
        answer.insert((parent[i]));
    }

    return answer.size();
}

int main() {
    solution(7, { { 1,0,0,0,0,0,1 },
        { 0,1,1,0,1,0,0 },
        { 0,1,1,1,0,0,0 },
        { 0,0,1,1,0,0,0 },
        { 0,1,0,0,1,1,0 },
        { 0,0,0,0,1,1,1 },
        { 1,0,0,0,0,1,1 } });

    for (int i = 0; i < 7; i++) cout << parent[i] << endl;

    return 0;
}