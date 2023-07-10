#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#include <iostream>

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

// 오름차순
priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> waiting_pq;
priority_queue<vector<int>, vector<vector<int>>, cmp> candidate_pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    int s = jobs.size();
    for(int i=0;i<s;i++){
        waiting_pq.push(jobs[i]);
    }
    
    int t = 0; // time
    while(1){
        while(!waiting_pq.empty()){
            vector<int> a = waiting_pq.top();
            if(a[0] <= t){
                waiting_pq.pop();
                candidate_pq.push(a);
            }
            else{
                break;
            }
        }
        
        // select job
        if(candidate_pq.empty() && waiting_pq.empty()){
            break;
        }
        else if(!candidate_pq.empty()){
            vector<int> job = candidate_pq.top();
            //cout << job[0] << endl;
            candidate_pq.pop();
            t += job[1];
            answer += (t - job[0]);
        }
        else if(!waiting_pq.empty() && candidate_pq.empty()){
            t = waiting_pq.top()[0];
        }
    }
    
    return answer / s;
}