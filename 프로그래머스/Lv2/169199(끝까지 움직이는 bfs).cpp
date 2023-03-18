#include <string>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

int minMove = 1e9;
int visited[102][102];

// R, D, L, U
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

class info{
public:
    int x, y;
    int move;
    
    info(int x, int y, int m)
        :x(x), y(y), move(m)
    {}
};

void bfs(vector<string> board, pii start){
    int r = board.size();
    int c = board[0].length();
    queue<info> q;
    q.push(info(start.first, start.second, 0));
    visited[start.first][start.second] = 1;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int move = q.front().move;
        
        if(board[x][y] == 'G'){
            minMove = std::min(minMove, move);
        }
        
        q.pop();
        
        int next_x = x, next_y = y;
        for(int i=0;i<4;i++){
            int temp_x = x;
            int temp_y = y;
            // go to end
            while(1){
                temp_x += dx[i];
                temp_y += dy[i];
                if(temp_x>=0&&temp_x<r&&temp_y>=0&&temp_y<c&&board[temp_x][temp_y] != 'D'){
                    next_x = temp_x;
                    next_y = temp_y;
                }
                else
                    break;
            }
            if(visited[next_x][next_y] == 0){
                visited[next_x][next_y] = 1;
                q.push(info(next_x, next_y, move + 1));   
            }
        }
    }
}

int solution(vector<string> board) {
    int i, j;
    
    pii start;
    int r = board.size();
    int c = board[0].length();
    int find = 0;
    
    fill(&visited[0][0], &visited[102][102], 0);
    
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(board[i][j] == 'R') {
                start = {i,j};
                find = 1;
                break;
            }
        }
        if(find) break;
    }
    
    bfs(board, start);
    
    if(minMove == 1e9) return -1;
    
    return minMove;
}