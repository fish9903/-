class Solution {
public:
    string answer = "";

    void expand(string& s, int left, int right){
        while(left >=0 && right < s.length()){
            if(s[left] != s[right]){
                break;
            }
            left--;
            right++;
        }

        if(answer.length() < right - left){
            answer = s.substr(left + 1, right - left - 1);
        }
    }

    string longestPalindrome(string s) {
        if(s.length() == 1) return s;

        int left = 0, right = 0;
        bool flag = true;
        for(int i=0;i<s.length();i++){
            expand(s, i, i);
            expand(s, i, i + 1);
        }

        return answer;
    }
};