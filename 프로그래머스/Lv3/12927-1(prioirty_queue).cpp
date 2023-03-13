#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int s = works.size();
    
    if(s==1){
        int t = works[0] - n;
        if(t <= 0) return 0;
        else return t*t;
    }
    
    priority_queue<int> pq;
    for(int i: works){
        pq.push(i);
    }
    
    while(n--){
        int t = pq.top();
        if(t==0) 
            return 0;
        pq.pop();
        t--;
        pq.push(t);
    }
    
    while(!pq.empty()){
        int t = pq.top();
        pq.pop();
        answer += t*t;
    }
    
    return answer;
}