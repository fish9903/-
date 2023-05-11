#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

// R D L U
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[101][101]; // 1: visited

int number_of_area = 0;
int max_size_of_one_area = 0;

void bfs(vector<vector<int>> picture, int m, int n, pii start, int target){
    // (0, 0) start
    queue<pii> q;
    q.push({start.first, start.second});
    visited[start.first][start.second] = 1;
    number_of_area++;
    
    int area_size = 1;
    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if(next_x>=0 && next_x<m && 
               next_y>=0 && next_y<n && 
               visited[next_x][next_y] == 0 &&
               picture[next_x][next_y] == target){
                q.push({next_x, next_y});
                visited[next_x][next_y] = 1;
                area_size++;
            }
        }
        
        max_size_of_one_area = std::max(max_size_of_one_area, area_size);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    number_of_area = 0;
    max_size_of_one_area = 0;
    fill_n(&visited[0][0], 101*101, 0); // visited 초기화
    
    // bfs
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(picture[i][j] != 0 && visited[i][j] == 0){
                bfs(picture, m, n, {i, j}, picture[i][j]);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}