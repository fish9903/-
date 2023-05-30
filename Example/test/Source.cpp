#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define DIV 1000000007

using namespace std;

long long answer;

void dfs(int n, vector<int> money, int i) {
    if (n <= 0) {
        if (n == 0) answer++;
    }
    else {
        dfs(n - money[i], money, i);
        if (i < money.size() - 1) {
            i++;
            dfs(n - money[i], money, i);
        }
    }
}

// n: �ݾ�
// money: �� ���� �迭
int solution(int n, vector<int> money) {

    // �������� ����
    sort(money.begin(), money.end());

    // dfs
    dfs(n, money, 0);

    return answer % DIV;
}

int main() {

    cout << solution(5, { 1, 2, 5 }) << endl;

    return 0;
}