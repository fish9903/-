#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> dp1, dp2;

int solution(vector<int> money) {
    int answer = 0;
    int s = money.size();
    dp1.resize(s, 0);
    dp2.resize(s, 0);
    
    // 첫번째 선택(마지막 제외)
    dp1[0] = money[0];
    dp1[2] = money[2] + money[0];
    for(int i=2;i<s-1;i++){
        if(i == 3){
            dp1[i] = max(money[i] + dp1[0], dp1[2]);
        }
        else{
            dp1[i] = max(money[i] + dp1[i-2], dp1[i-1]);
        }        
    }
    int first_max = *max_element(dp1.begin(), dp1.end());
    
    
    // 첫번째 선택 x
    dp2[1] = money[1];
    for(int i=2;i<s;i++){
        dp2[i] = max(money[i] + dp2[i-2], dp2[i-1]);
    }
    int second_max = *max_element(dp2.begin(), dp2.end());

    answer = max(first_max, second_max);
    return answer;
}