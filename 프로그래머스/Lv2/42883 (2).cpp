#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int i = 0;
    int l = number.length();
    while(k > 0 && i < l - 1){
        if(number[i] < number[i + 1]){
            k--;
            //cout << i << endl;
            number = number.erase(i, 1);
            // cout << number << endl;
            i = -1;
            l = number.length();
        }
        
        i++;
    }
    
    while(k > 0){
        number = number.erase(number.length() - 1, 1);
        k--;
    }
    
    return number;
}