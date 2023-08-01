#include <string>
#include <vector>
#include <queue>

using namespace std;

int cnt = 0;

void dfs(vector<int>& numbers, int target, int start, int end, int sum){
    if(start > end) return;
    else if(start == end && sum == target){
        cnt++;
    }
    else{
        dfs(numbers, target, start + 1, end, sum + numbers[start+1]);
        dfs(numbers, target, start + 1, end, sum - numbers[start+1]);
    }
}

void bfs(vector<int>& num, int target){
    queue<pair<int,int>> q1;
    q1.push(make_pair(0,num[0]));
    q1.push(make_pair(0,-num[0]));
    
    while(!q1.empty()){
        int idx = q1.front().first;
        int res = q1.front().second;
        q1.pop();
        
        if(idx + 1 < num.size()){
            if(idx + 1 == num.size() - 1 && res + num[idx + 1] == target){
                cnt += 1;
            }
            else if(idx + 1 == num.size() - 1 && res - num[idx + 1] == target){
                cnt += 1;
            }
            else{
                q1.push(make_pair(idx + 1, res + num[idx + 1]));
                q1.push(make_pair(idx + 1, res - num[idx + 1]));
            }
        }
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int s = numbers.size();
    // dfs(numbers, target, 0, s-1, numbers[0]);
    // dfs(numbers, target, 0, s-1, -numbers[0]);
    bfs(numbers, target);
    
    return cnt;
}