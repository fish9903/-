#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//int n; // 숫자 개수
const int INF = 1e9;
int solution(vector<string> arr)
{
    int answer;
    vector<int> nums;
    vector<char> ops;
    for(int i = 0; i < arr.size(); i++){
        if(i%2 == 1) ops.push_back(arr[i][0]);
        else nums.push_back(stoi(arr[i]));
    }

    int n = nums.size();
    int o = ops.size();
    int max_dp[n][n]; // max_dp[i][j] = i~j까지 최대
    int min_dp[n][n]; // min_dp[i][j] = i~j까지 최소
    
    fill_n(&max_dp[0][0], n*n, -INF);
    fill_n(&min_dp[0][0], n*n, INF);
    
    // for(int i=0;i<n;i++){
    //     max_dp[i][i] = nums[i];
    //     min_dp[i][i] = nums[i];
    // }
    for(int step = 0; step < nums.size(); step++) { // step = 간격
        for(int i = 0; i < nums.size() - step; i++) { // i~j
            int j = i + step;
            if(step == 0) {
                max_dp[i][j] = nums[i];
                min_dp[i][j] = nums[i];
            } 
            else {
                for(int k = i; k < j; k++) {
                    if(ops[k] == '+') {
                        //max = max + max
                        max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] + max_dp[k+1][j]);
                        //min = min + min
                        min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] + min_dp[k+1][j]);
                    }
                    else {
                        //max = max - min
                        max_dp[i][j] = max(max_dp[i][j], max_dp[i][k] - min_dp[k+1][j]);
                        //min = min - max
                        min_dp[i][j] = min(min_dp[i][j], min_dp[i][k] - max_dp[k+1][j]);                        
                    }
                }
            }
            
        }
    }
    
    answer = max_dp[0][nums.size()-1];
    
    return answer;
}