#include <iostream>

using namespace std;

int T, n;
int answer;

void dfs(int sum){
    if(sum == n){
        answer++;
        return;
    }
    else if(sum > n){
        return;
    }

    for(int i=1;i<=3;i++){
        dfs(sum + i);
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        answer = 0;
        dfs(0);
        cout << answer << endl;
    }

    return 0;
}