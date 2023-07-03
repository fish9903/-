#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

queue<int> q;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for(int i=0;i<progresses.size();i++) q.push(progresses[i]);
    
    int done = 0;
    int days;
    int i = 0;
    int p = q.front();
    q.pop();
    
    // 작업 진행 할 일 수
    days = ceil(double(100 - p) / speeds[i]);
    done++;
    
    i++;

    while(!q.empty()){
        p = q.front();
        q.pop();
        p += (days * speeds[i]);
        
        if(p < 100){
            answer.push_back(done);
            days += ceil(double(100 - p) / speeds[i]);
            done = 1;
        }
        else{
            done++;
        }
        i++;
    }

    answer.push_back(done);
    
    return answer;
}