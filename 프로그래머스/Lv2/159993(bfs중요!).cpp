#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define pii pair<int,int>

using namespace std;

int Move = 1e9;

// R, D, L, U
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

// 저장해야할 것들이 2개 이상(pair로 부족)일 경우, bfs 하는 법
// class를 만들어서 사용하는 것도 가능하다.
// bfs는 항상 최적의 결과 보장가능 --> 바로 return 가능함
int bfs(vector<string> maps, pii start, char target){
    int r = maps.size();
    int c = maps[0].length();
    int count = 0;
    vector<vector<int>> visited(r, vector<int>(c, 0));
    queue<pii> q;
    
    q.push(start);
    visited[start.first][start.second] = 1;
    while(!q.empty()){
        int q_size = q.size();
        while(q_size--){
            int x = q.front().first;
            int y = q.front().second;

            if(maps[x][y] == target){
                return count;
            }
            
            q.pop();

            for(int i=0;i<4;i++){
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                if(next_x>=0 && next_x<r && next_y>=0 && next_y<c && maps[next_x][next_y] != 'X' && visited[next_x][next_y] == 0){
                    visited[next_x][next_y] = 1;
                    q.push({next_x,next_y});
                }
            }
        }
        count++;
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].length();
    
    pii start;
    pii lever;
    pii exit;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j] == 'S') start = {i,j};
            else if(maps[i][j] == 'L') lever = {i,j};
            else if(maps[i][j] == 'E') exit = {i,j};
        }
    }
    
    
    // find lever
    int result = bfs(maps, start, 'L');
    if(result == -1) return -1;
    answer += result;
    
    // find exit
    result = bfs(maps, lever, 'E');
    if(result == -1) return -1;
    answer += result;
    
    
    return answer;
}