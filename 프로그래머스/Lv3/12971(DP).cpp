#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dp problem

int solution(vector<int> sticker)
{
    if(sticker.size() <= 3) return *max_element(sticker.begin(), sticker.end());
    
    int answer =0;
    int i;
    
    // dp, dp2: i 번째까지의 최대 합 저장
    vector<int> dp(sticker.size(), 0); // 첫 번째 선택
    vector<int> dp2(sticker.size(), 0); // 첫 번째 선택 x
    
    dp[0] = sticker[0];
    dp[1] = dp[0]; // 첫 번째를 선택했으므로 두 번째는 선택 못함(최대합 유지)
    
    dp2[0] = 0;
    dp2[1] = sticker[1];
    
    // 첫 번째 인덱스 선택
    for(i=2;i<sticker.size()-1;i++){
        dp[i] = std::max(dp[i-2] + sticker[i], dp[i-1]);
    }
    
    // 첫 번째 인덱스 선택 x
    for(i=2;i<sticker.size();i++){
        dp2[i] = std::max(dp2[i-2] + sticker[i], dp2[i-1]);
    }
    
    
    
    int max1 = *max_element(dp.begin(), dp.end());
    int max2 = *max_element(dp2.begin(), dp2.end());
    
    return answer = std::max(max1, max2);
}