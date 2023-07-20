#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

// R, D, L, U
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class Node{
public:
    pii x;
    int cnt;
    
    Node(pii x, int cnt)
        :x(x), cnt(cnt)
        {}
};

queue<Node> q;
int visited[102][102] = {0, };

int answer = 1e9;

void bfs(vector<vector<int> > maps){
    int n = maps.size();
    int m = maps[0].size();
    int cnt = 1;
    int flag = 0;
    
    pii start = {0, 0};
    pii target = {n-1, m-1};
    q.push(Node(start, cnt));
    visited[0][0] = 1;
    
    while(!q.empty()){
        pii now = q.front().x;
        cnt = q.front().cnt;
        q.pop();
        
        for(int i=0;i<4;i++){
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];
            
            if(next_x >=0 && next_x < n && next_y >=0 && next_y < m && maps[next_x][next_y] == 1 && visited[next_x][next_y] != 1){
                if(make_pair(next_x, next_y) == target){
                    answer = cnt + 1;
                    return;
                }
                q.push(Node({next_x, next_y}, cnt + 1));
                visited[next_x][next_y] = 1;
            }
        }
    }
    
    answer = -1;
}

int solution(vector<vector<int> > maps)
{    
    bfs(maps);
    
    return answer;
}