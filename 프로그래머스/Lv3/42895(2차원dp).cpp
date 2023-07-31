#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int solution(int N, int number) {
    
    if(N == number) return 1;
    
    vector<unordered_set<int>> dp(9); // 1~9
    
    int n = 0;
    for(int i=1;i<=8;i++){
        n = n*10 + N;
        dp[i].insert(n);
    }
    
    for(int k=1; k<=8; k++){
        
        for(int i=1; i<k; i++){
            for(int j=1; j<k; j++){
                
                if(i+j == k){
                    for(int a : dp[i]){
                        for(int b : dp[j]){
                            dp[k].insert(a+b);
                            if(a-b>0) dp[k].insert(a-b);
                            dp[k].insert(a*b);
                            if(a/b>0) dp[k].insert(a/b);
                        }
                    }
                }
            }
        }

        if(dp[k].count(number) == 1)
            return k;
    }
    return -1;
}