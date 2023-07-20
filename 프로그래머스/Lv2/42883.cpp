#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int flag = 1;
    while(flag){
        for(int i=1;i<number.length();i++){
            if(number[i-1] < number[i] && k >= 1){
                number.erase(i-1, 1);
                k--;
                if(k == 0)
                    flag = 0;
                
                break;
            }
            
            if(i == number.length()-1)
                flag = 0;
        }
    }
    
    while(k--){
        number.erase(number.length()-1, 1);
    }
    
    answer = number;
    return answer;
}