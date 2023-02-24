#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> m; // weight, index
int weightCnt[1001] = { 0, };

int BS(vector<int> v, int s, int e, int target) {
    while (s < e) {
        int mid = (s + e) / 2;
        if (v[mid] > 2 * target) return mid;
        else s = mid + 1;
    }
    return s;
}

long long solution(vector<int> w) {
    long long answer = 0;

    int i, j;
    int s = w.size();
    sort(w.begin(), w.end());
    int cnt = 0;
    for (i = 0; i < s; i++) {
        int target = w[i];
        int j = BS(w, i + 1, s - 1, target);
        cnt = 0;
        for (; j > i; j--) {
            if (w[i] == w[j] || w[i] * 2 == w[j] || w[i] * 3 == w[j] * 2 || w[i] * 4 == w[j] * 3) {
                cnt++;
            }
        }
        answer += cnt;
    }

    return answer;
}