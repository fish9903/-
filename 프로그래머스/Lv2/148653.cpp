#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int,int>

using namespace std;

int solution(int storey) {
    int answer = 0;
    string s = to_string(storey);
    int digit = s.length(); // 자릿수
    vector<int> v; // cnt
    
    queue<pii> q;
    int cnt = 0;
    q.push({storey, cnt}); // num, cnt
    while(!q.empty()){
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(num < 10){
            v.push_back(cnt + num);
            v.push_back(cnt + 10 - num + 1); // 반올림: + 1
        }
        else{
            int remain = num % 10;
            num /= 10;
            q.push({num, cnt+remain});
            q.push({num+1, cnt+10-remain});
        }
    }
    sort(v.begin(), v.end());
    
    answer = v[0];
    
    return answer;
}