class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int start = 0, end = 0; // start, end index
        // unordered_set<char> set;        
        // int max_length = 0;
        
        // while(end < s.size()) {
        //     if(set.find(s[end]) != set.end()) { // find
        //         set.erase(set.find(s[start]));
        //         start++;
        //     }  
        //     else { // not found
        //         set.insert(s[end]);
        //         end++;
        //         max_length = std::max(max_length, end - start);
        //     }
        // }

        int start = 0, end = 0;
        int max_length = 0;
        unordered_map<char, int> um; // char, index

        for(end = 0; end<s.size(); end++) {
            // find
            if(um.count(s[end]) && start <= um[s[end]]) {
                start = um[s[end]] + 1;
            }
            um[s[end]] = end;
            // start and end can point same index
            max_length = std::max(max_length, end - start + 1); 
        }
        
        return max_length;
    }
};