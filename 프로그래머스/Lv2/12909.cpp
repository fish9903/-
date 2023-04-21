#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            if(s[i] == ')') return false;
            
            st.push(s[i]);
        }
        else if(st.top() == s[i]){
            st.push(s[i]);
        }
        else{
            st.pop();
        }
    }
    if(st.empty()) return true;
    else return false;

    return answer;
}