#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
// dp
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    vector<vector<int>> dp1(m+2, vector<int>(n+2, 0)); // right
    vector<vector<int>> dp2(m+2, vector<int>(n+2, 0)); // down
    
    dp1[1][1] = 1;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            
            if(city_map[i-1][j-1] == 0) {
                dp1[i][j + 1] += (dp1[i][j] + dp2[i][j]) % MOD;
                dp2[i + 1][j] += (dp1[i][j] + dp2[i][j]) % MOD;
            } 
            else if(city_map[i-1][j-1] == 2) {
                dp1[i][j + 1] += dp1[i][j] % MOD;
                dp2[i + 1][j] += dp2[i][j] % MOD;
            }
            
        }
    }       
    
    return (dp1[m][n] + dp2[m][n]) % MOD;
}