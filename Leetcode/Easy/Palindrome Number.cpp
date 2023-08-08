class Solution {
public:
    bool isPalindrome(int x) {
        // int to string 사용
        // if(x < 0) 
        //     return false;

        // string s = to_string(x);

        // for(int i=0;i<s.length()/2;i++){
        //     if(s[i] != s[s.length()-1 - i]){
        //         return false;
        //     }
        // }

        // return true;

        // reserved 사용
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return (x == reversed) || (x == reversed / 10);
    }
};