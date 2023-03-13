#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int board[102][102];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    fill(&board[0][0], &board[101][102], 0);

    for(int i=0;i<puddles.size();i++){
        board[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    board[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(board[i][j] != -1){
                if(board[i][j-1] != -1) board[i][j] = (board[i][j] + board[i][j-1]) % 1000000007;
                if(board[i-1][j] != -1) board[i][j] = (board[i][j] + board[i-1][j]) % 1000000007;   
            }            
        }
    }
    answer = board[n][m];
    
    // for(int i=0;i<=n+1;i++){
    //     for(int j=0;j<=m+1;j++)
    //         cout << board[i][j] << ' ';
    //     cout <<endl;
    // }
    
    return answer;
}