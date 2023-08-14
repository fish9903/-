class Solution {
public:
    static bool cmp(int a, int b){
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        return s1 > s2;
    }

    string largestNumber(vector<int>& nums) {
        string answer = "";
        sort(nums.begin(), nums.end(), cmp);

        for(int i=0;i<nums.size();i++){
            answer += to_string(nums[i]);
        }

        // remove 0
        if(answer[0] == '0')
            return "0";

        return answer;
    }
};