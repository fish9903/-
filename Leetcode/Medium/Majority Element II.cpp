class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer;
        set<int> s;

        int size = nums.size();
        int border = size / 3;

        sort(nums.begin(), nums.end());

        int cnt = 0;
        vector<int>::iterator iter = nums.begin();
        int cur_num = *iter;

        for(;iter!=nums.end();iter++){
            if(cur_num != *iter){
                // update cur_num, cnt
                cur_num = *iter;
                cnt = 0;
            }

            cnt++;
            if(cnt > border && s.find(*iter)==s.end()){
                answer.push_back(*iter);
                s.insert(*iter);
            }
        }

        return answer;
    }
};