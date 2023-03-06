#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    if(triangle.size() == 1) return triangle[0][0];
    
    vector<vector<int>> dp = triangle;
    for(int i=0;i<triangle.size()-1;i++){
        for(int j=0;j<triangle[i].size();j++){
            if(i+1 < triangle.size()){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + triangle[i+1][j]);
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + triangle[i+1][j+1]);
            }
        }
    }
    
//     for(auto i: dp){
//         for(auto j: i){
//             cout << j << ' ';
//         }
//         cout << endl;
//     }
    
    return *max_element(dp[triangle.size()-1].begin(), dp[triangle.size()-1].end());
}