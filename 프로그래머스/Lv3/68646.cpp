#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp_l_min[1000000 + 1];
int dp_r_min[1000000 + 1];

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    
    dp_l_min[0] = a[0];
    dp_r_min[n-1] = a[n-1];
    
    for(int i=1;i<n;i++){
        dp_l_min[i] = std::min(dp_l_min[i-1], a[i]);
    }
    for(int i=n-2;i>=0;i--){
        dp_r_min[i] = std::min(dp_r_min[i+1], a[i]);
    }
    
    for(int i=0;i<n;i++){
        if(i == 0 || i == n-1){
            answer++;
        }
        else if(dp_l_min[i-1] > a[i] || dp_r_min[i+1] > a[i]){
            answer++;
        }
    }
    
    return answer;
}