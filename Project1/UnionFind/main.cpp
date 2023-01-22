#include <iostream>

using namespace std;

int v, e;
int parent[10000 + 1]; // parent ���� ����

// parent ã��
int FindParent(int* parent, int x) {
	if (parent[x] != x) parent[x] = FindParent(parent, parent[x]);
	return parent[x]; // �ϳ��� �ֻ� �θ�� ����, x�� ��ȯ�ϸ� �ٷ� ���ܰ� �θ�� ����
}

// ���� ��ġ��
void UnionParent(int a, int b) {
	int a_p = FindParent(parent, a);
	int b_p = FindParent(parent, b);
	if (a_p < b_p) parent[b] = a;
	else parent[a] = b;
}

int main(void) {
    cin >> v >> e;

    // �θ� ���̺�󿡼�, �θ� �ڱ� �ڽ����� �ʱ�ȭ
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    // Union ������ ���� ����
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        UnionParent(a, b);
    }

    // �� ���Ұ� ���� ���� ����ϱ�
    cout << "�� ���Ұ� ���� ����: ";
    for (int i = 1; i <= v; i++) {
        cout << FindParent(parent, i) << ' ';
    }
    cout << '\n';

    // �θ� ���̺� ���� ����ϱ�
    cout << "�θ� ���̺�: ";
    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';
}