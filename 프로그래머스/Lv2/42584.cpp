#include <string>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

priority_queue<pii> pq;

vector<int> solution(vector<int> prices) {
    int s = prices.size();
    vector<int> answer(s);
    
    int time = 0;
    for(int i=0;i<s;i++){
        time++;
        pq.push({prices[i], i});
        
        while(1){
            pii x = pq.top();
            if(x.first > prices[i]){ // 하락
                pq.pop();
                answer[x.second] = time - x.second - 1;
            }
            else{
                break;
            }
        }
    }
    
    // queue flush
    while(!pq.empty()){
        pii x = pq.top();
        pq.pop();
        
        answer[x.second] = time - x.second - 1;
    }
    
    answer[s-1] = 0;
    return answer;
}