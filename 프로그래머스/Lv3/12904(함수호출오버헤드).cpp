#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s)
{
    // window size
    int l = s.length();
    while(l){
        for(int i=0;i<s.length()-l+1;i++){
            // string target = s.substr(i,l);
            // if(isPal(target)) return l;
            int start = i;
            int end = i + l - 1;
            bool flag = true;
            while(start < end){
                if(s[start] != s[end]){
                    flag = false;
                    break;
                }
                start++;
                end--;
            }
            
            if(flag) return l;
        }
        l--;
    }

    return 1;
}