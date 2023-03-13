#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int board[102][102];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    fill(&board[0][0], &board[101][102], 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            board[i][j] = puddles[i - 1][j - 1];
        }
    }


    return answer;
}
