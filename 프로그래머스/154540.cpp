#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define pii pair<int, int>

using namespace std;

// R, D, L, U
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pii> v;
int visited[100][100];
int sum;

void bfs(vector<string>& maps, int i, int j) {
    sum = maps[i][j] - '0';
    queue<pii> q;
    q.push({i, j});
    v.push_back({i, j});
    visited[i][j] = 1;

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int next_x = now_x + dx[k];
            int next_y = now_y + dy[k];
            if(next_x < maps.size() && next_x >= 0 && next_y < maps[i].size() && next_y >= 0 
               && maps[next_x][next_y] != 'X' && visited[next_x][next_y] == 0)
            {
                sum += (maps[next_x][next_y] - '0');
                q.push({next_x, next_y});
                v.push_back({next_x, next_y});
                visited[next_x][next_y] = 1;
            }
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    //vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), 0)); // 1: visited
    fill(&visited[0][0], &visited[0][0] + 100 * 100, 0); // 1: visited
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if(visited[i][j] == 0 && maps[i][j] != 'X'){
                v.clear();
                bfs(maps, i, j);
                if(v.size() >= 1) {
                    answer.push_back(sum);
                }
            }
        }
    }
    if(answer.empty()){
        answer.push_back(-1);
        return answer;
    }
    sort(answer.begin(), answer.end());
    return answer;
}