#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;

deque<int> dq; // {max index, min index}, max만나면 min 삭제 가능
priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> stones, int k) {
    if(stones.size() == 1) return stones[0];
    if(stones.size() == 2) return std::max(stones[0], stones[1]);
    
    int answer = 0;
    
    dq.resize(k, 0);
    
    // fisrt k elements
    for(int i=0;i<k;i++){
        while(!dq.empty() && stones[i] >= stones[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    pq.push(stones[dq.front()]);
    
    for(int i=k;i<stones.size();i++){
        // delete out of index in dp
        while(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        
        while(!dq.empty() && stones[i] >= stones[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        
        pq.push(stones[dq.front()]);
    }
    
    return answer = pq.top();
}