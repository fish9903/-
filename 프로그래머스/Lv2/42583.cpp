#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define pii pair<int, int>

using namespace std;

queue<int> pending; // 대기중인 트럭들
queue<pii> on; // 올라가 있는 트럭들

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    for(int i=0;i<truck_weights.size();i++) pending.push(truck_weights[i]);
    
    int current_weight = 0;
    while(!pending.empty()){
        answer++; // current time
        
        int truck = pending.front();
        
        // 트랙 내리기
        if(answer - on.front().second >= bridge_length){
            current_weight -= on.front().first;
            on.pop();
        }
        
        // 트럭 올리기
        if(current_weight + truck <= weight){
            on.push({truck, answer}); // 올라간 시각 저장
            pending.pop();
            current_weight += truck;
        }
    }
    
    // 마지막 트럭 전진
    answer += bridge_length;
    
    return answer;
}