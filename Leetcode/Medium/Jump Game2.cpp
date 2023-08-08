class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        if(n == 1) return 0;

        vector<int> dp(n, 1e9);

        dp[n-1] = 0;

        for(int i=n-2;i>=0;i--){
            if(nums[i] == 0) 
                continue;

            if(i + nums[i] >= n-1) 
                dp[i] = 1;
            else
                dp[i] = *min_element(dp.begin() + i, dp.begin() + i + nums[i] + 1) + 1;
        }


        return dp[0];
    }
};