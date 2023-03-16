#include <string>
#include <vector>
#include <iostream>

#define pii pair<int,int>

using namespace std;

int Move = 1e9;
int flag = 0;

// R, D, L, U
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(vector<string> maps, vector<vector<int>> visited, int x, int y, char target, int count) {
    visited[x][y] = 1;
    if (maps[x][y] == target) {
        flag = 1;
        Move = std::min(Move, count);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (next_x >= 0 && next_x < maps.size() && next_y >= 0 && next_y < maps[0].length() && maps[next_x][next_y] != 'X' && visited[next_x][next_y] == 0) {
            dfs(maps, visited, next_x, next_y, target, count + 1);
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0;

    int n = maps.size();
    int m = maps[0].length();

    pii start;
    pii lever;
    pii exit;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') start = { i,j };
            else if (maps[i][j] == 'L') lever = { i,j };
            else if (maps[i][j] == 'E') exit = { i,j };
        }
    }


    vector<vector<int>> visited(n, vector<int>(m, 0));

    if (!flag) return -1;

    dfs(maps, visited, start.first, start.second, 'L', 0);
    answer += Move;


    return answer;
}

int main() {
    solution({ "SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE" });
    return 0;
}