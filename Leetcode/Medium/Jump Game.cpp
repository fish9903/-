class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;

        vector<int> dp(n, 0);

        dp[n-1] = 1;
        if(nums[n-2] >= 1) 
            dp[n-2] = 1;
        else
            dp[n-2] = 0;

        for(int i=n-3;i>=0;i--){
            if(i + nums[i] >= n - 1){
                dp[i] = 1;
            }
            else if(*max_element(dp.begin() + i, dp.begin() + i + nums[i] + 1) == 1){
                dp[i] = 1;
            }
            else{
                dp[i] = 0;
            }
        }

        return dp[0];
    }
};