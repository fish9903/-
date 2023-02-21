#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iostream>

#define pii pair<int,int>

using namespace std;

int solution(int storey) {
    int answer = 0;
    string s = to_string(storey);
    int digit = s.length(); // �ڸ���
    int div1 = pow(10, digit - 1);
    int div2 = pow(10, digit);
    vector<int> v; // cnt

    queue<pii> q;
    int cnt = 0;
    q.push({ storey, cnt }); // num, cnt
    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (num < 10) {
            v.push_back(cnt + num);
            v.push_back(cnt + 10 - num + 1); // �ݿø�: + 1
        }
        else {
            int remain = num % 10;
            num /= 10;
            q.push({ num, cnt + remain });
            q.push({ num + 1, cnt + 10 - remain });
        }
    }
    sort(v.begin(), v.end());

    answer = v[0];

    return answer;
}
int main() {
    cout << solution(555);

    return 0;
}