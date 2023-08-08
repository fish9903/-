class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        unordered_map<char, int> um;
        int left = 0;
        int right = 0;

        for(right = 0; right < s.length(); right++){
            // 중복된 문자
            if(um.count(s[right]) != 0 && left <= um[s[right]]){
                left = um[s[right]] + 1;             
            }

            um[s[right]] = right;

            max_length = std::max(max_length, right - left + 1);
        }

        return max_length;
    }
};