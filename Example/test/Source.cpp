#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <iostream>


using namespace std;

int answer = 0;
vector<pair<int, int>> queen;
set<int> setX;
set<int> setY;

int solution(int n) {
    int i, j;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<pair<int, int>> candidate;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            candidate.push_back({ i, j });
        }
    }

    // combination
    vector<int> c(n * n, 0);
    fill(c.end() - n, c.end(), 1);
    do {
        vector<vector<int>> temp = board;
        queen.clear();
        setX.clear();
        setY.clear();

        for (i = 0; i < n * n; i++) {
            if (c[i] == 1 && !setX.count(candidate[i].first) && !setY.count(candidate[i].second)) { // select
                queen.push_back({ candidate[i].first, candidate[i].second });
                setX.insert(candidate[i].first);
                setY.insert(candidate[i].second);
                //temp[candidate[i].first][candidate[i].second] = 1; // queen
            }
        }

        int s = queen.size();
        int flag = 1;
        if (s == n) {
            for (i = 0; i < s - 1; i++) {
                for (j = i + 1; j < s; j++) {
                    if (queen[i].first == queen[j].first || queen[i].second == queen[j].second || abs(queen[i].first - queen[j].first) == abs(queen[i].second - queen[j].second)) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) {
                for (auto a : queen)
                    cout << a.first << ',' << a.second << endl;
                answer++;
            }
        }
            
    } while (next_permutation(c.begin(), c.end()));


    return answer;
}

int main() {
    solution(4);
    cout << answer << endl;

    return 0;
}