#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

multiset<string> want_set;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int size = want.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<number[i];j++){
            want_set.insert(want[i]);
        }
    }
    
    size = discount.size();
    multiset<string> temp;
    for(int i=0;i<9;i++){
            temp.insert(discount[i]);
    }
    int first;
    for(int i=0;i<=size-10;i++){
        first = i;
        temp.insert(discount[i]);
        
        if(temp == want_set) 
            answer++;
        
        multiset<string>::iterator it = temp.find(discount[first]);
        temp.erase(it);
    }
    
    return answer;
}