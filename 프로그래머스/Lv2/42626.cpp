#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    int s = scoville.size();
    for(int i=0;i<s;i++){
        pq.push(scoville[i]);
    }
    
    int x;
    int a, b, c;
    while(1){
        x = pq.top();
        if(x >= K){
            return answer;
        }
        
        if(pq.size() == 1){
            return -1;
        }
        
        // mix
        answer++;
        
        a = x;
        pq.pop();
        b = pq.top();
        pq.pop();
        
        c = a + 2*b;
        pq.push(c);
    }
    
    return answer;
}