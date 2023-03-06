#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> dq;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0, 0};
    
    int s = operations.size();
    for(int i=0;i<s;i++){
        string instr = operations[i];
        char action = instr[0];
        int data = stoi(instr.substr(2, instr.size()-2));
        
        if(action == 'I'){
            dq.push_back(data);
        }
        else if(action == 'D'){
            if(data == 1 && !dq.empty()){
                dq.pop_back();
            }
            else if(data == -1 && !dq.empty()){
                dq.pop_front();
            }
        }
        sort(dq.begin(), dq.end());
    }
    
    if(!dq.empty()){
        answer[0] = dq.back();
        answer[1] = dq.front();
    }
    
    return answer;
}