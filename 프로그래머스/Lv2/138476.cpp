#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    sort(tangerine.begin(), tangerine.end());
    
    int s = tangerine.size();
    int count = 0;
    priority_queue<int> pq;
    for(int i=0;i<s;i+=count){
        count = upper_bound(tangerine.begin(), tangerine.end(), tangerine[i]) - lower_bound(tangerine.begin(), tangerine.end(), tangerine[i]);
        pq.push(count);
    }
    
    while(!pq.empty()){
        if(k <= 0) break;
        
        int x = pq.top();
        pq.pop();
        answer++;
        k -= x;
    }
    
    return answer;
}