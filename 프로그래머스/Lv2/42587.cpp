#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

queue<pii> q; // <priority, location>

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int s = priorities.size();
    for(int i=0;i<s;i++){
        q.push({priorities[i], i});
    }
    
    sort(priorities.begin(), priorities.end());
    
    int count = 1;
    while(!q.empty()){
        pii x = q.front();
        q.pop();
        
        s = priorities.size();
        if(x.first == priorities[s-1]){
            if(x.second == location){
                return count;
            }
            priorities.pop_back();
            count++;
        }
        else{
            q.push(x);
        }
    }
    
    return answer;
}