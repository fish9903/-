#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define pii pair<int, int>

using namespace std;

int graph[102][102]; // x win y --> [x][y] = 1, lose = -1

int ComputeRank(int n, int a){
    int sum = 0;
    for(int i=1;i<=n;i++) sum += graph[a][i];
    return n + sum + 1;
}

// n = [1, n]
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    fill_n(&graph[0][0], 102*102, 0);
    
    int row = results.size(); // col = 2
    for(int i=0;i<row;i++){
        graph[results[i][0]][results[i][1]] = 1; // win
        graph[results[i][1]][results[i][0]] = -1; // lose
    }
    
    // i: 거처가는 노드
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(graph[j][k] != 0) continue; // 0만 갱신
                if(graph[j][i] == graph[i][k]) 
                    graph[j][k] = graph[j][i];
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int flag = 1;
        for(int j=1;j<=n;j++){
            if(graph[i][j] == 0 && i != j){
                flag = 0;
                break;
            }
        }
        if(flag) answer++;
    }
    
    return answer;
}