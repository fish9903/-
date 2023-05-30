#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    sort(money.begin(), money.end());

    // 금액 i를 만들 수 있는 개수
    vector<long long> dp(n+1, 0);

    for(int i=0; i<=n ;i++){
         if(i % money[0] == 0)
             dp[i]=1;
    }

    for(int i=1; i<money.size(); i++){
        for(int j=money[i]; j<=n; j++){
            dp[j] += dp[j-money[i]];
        }
    }

    answer = dp[n] % 1000000007;
    return answer;
}