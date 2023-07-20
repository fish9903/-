#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

class Node{
public:
  int a, b;
  int cnt;
    
  Node(int a, int b, int cnt)
      :a(a), b(b), cnt(cnt) {}
};


vector<vector<int>> r;

// R, D, L, U
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int map[102][102] = {0, }; // size * 2
int visited[102][102] = {0, };

bool isInside(int x, int y){
    for(int i=0;i<r.size();i++){
        if(r[i][0]*2 < y && r[i][1]*2 < x && r[i][2]*2 > y && r[i][3]*2 > x)
            return true;
    }
    return false;
}

void makeMap(){
    for(int i=0;i<r.size();i++){
        vector<int> target = r[i];
        for(int j=target[0]*2;j<=target[2]*2;j++){
            if(!isInside(target[1]*2, j)) map[target[1]*2][j] = 1;
            if(!isInside(target[3]*2, j)) map[target[3]*2][j] = 1;
        }
        for(int j=target[1]*2;j<=target[3]*2;j++){
            if(!isInside(j, target[0]*2)) map[j][target[0]*2] = 1;
            if(!isInside(j, target[2]*2)) map[j][target[2]*2] = 1;
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    r = rectangle;
    
    // make map
    makeMap();
    
    // bfs
    queue<Node> q;
    q.push(Node(characterY*2, characterX*2, 0));
    visited[characterY*2][characterX*2] = 1;
    while(!q.empty()){
        Node now = q.front();
        q.pop();
        
        int next_x, next_y;
        for(int i=0;i<4;i++){
            next_x = now.a + dx[i];
            next_y = now.b + dy[i];
            if(next_x == itemY*2 && next_y == itemX*2){
                answer = now.cnt + 1;
                return answer/2;
            }
            if(map[next_x][next_y] == 1 && visited[next_x][next_y] == 0){
                q.push(Node(next_x, next_y, now.cnt + 1));
                visited[next_x][next_y] = 1;
            }
        }
    }
    
    return answer;
}