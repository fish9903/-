#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    deque<int> dq(people.begin(), people.end());
    sort(dq.begin(), dq.end());
    
    while(dq.size() > 1){
        int f = dq.front();
        int b = dq.back();
        int Max = dq.back();
        int Min = dq.front();
        
        if(limit - Max < Min){
            dq.pop_back();
            answer++;
        }
        else{
            dq.pop_back();
            dq.pop_front();
            answer++;
        }
    }
    
    if(!dq.empty()) answer++;
    
    return answer;
}