#include <string>
#include <vector>

using namespace std;

int board[15];
int answer;

bool Valid(int depth){
    for(int i=0;i<depth;i++){
        if(board[depth] == board[i] || depth == i || abs(board[depth]-board[i]) == abs(depth - i)){
            return false;
        }
    }
    return true;
}

void BackTracking(int depth, int n){
    if(depth == n){
        answer++;
        return;
    }
    
    for(int i=0;i<n;i++){
        board[depth] = i;
        if(Valid(depth)){
            BackTracking(depth+1, n);
        }
    }
}

int solution(int n) {    
    BackTracking(0, n);
    
    return answer;
}