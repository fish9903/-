#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1
// 29
// 308
// 4567

// 왼쪽아래 --> 오른쪽 --> 왼쪽위 --> 왼쪽아래 --> ...

// 0: 아래
// 1: 오른쪽
// 2: 왼쪽위
int head = 0;
int move_x[3] = {1, 0, -1};
int move_y[3] = {0, 1, -1};

vector<int> solution(int n) {
    vector<int> answer;
    
    int max_num = 0;
    for(int i=1;i<=n;i++){
        max_num += i;
    }
    
    // **init**
    vector<vector<int>> map(n, vector<int>(n, -1));
    int num = 1;
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i+1;j++){
    //         map[i][j] = num;
    //         num++;
    //     }
    // }

    // -------------
    num = 1;
    int x = 0, y = 0;
    int next_x, next_y;
    while(1){
        if(map[x][y] != -1){
            break;
        }
        
        map[x][y] = num;
        num++;
        
        // move
        next_x = x + move_x[head];
        next_y = y + move_y[head];
        
        if(next_x<0||next_x>=n||next_y<0||next_y>=n||(map[next_x][next_y]!=-1&&map[next_x][next_y]<num)){ // 막힘
            head = (head + 1) % 3;
            
            next_x = x + move_x[head];
            next_y = y + move_y[head];
        }
           
        x = next_x;
        y = next_y;
    }
    
    // **show**
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << map[i][j] << '\t';
    //     }
    //     cout << endl;
    // }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            answer.push_back(map[i][j]);
        }
    }
    
    return answer;
}