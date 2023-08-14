class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int buy = -1, sell = -1;
        int n = prices.size();
        
        for(int i=0;i<n-1;i++){
            if(prices[i] < prices[i+1]){
                if(buy == -1) buy = prices[i];
                sell = prices[i+1];
            }
            else{
                answer += (sell - buy);
                buy = -1;
                sell = -1;
            }
        }

        answer += (sell - buy);

        return answer;
    }
};