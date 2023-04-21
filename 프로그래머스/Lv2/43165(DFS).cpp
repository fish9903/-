#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void dfs(vector<int> numbers, int target, int start, int end, int sum){
    if(start > end) return;
    else if(start == end && sum == target){
        cnt++;
    }
    else{
        dfs(numbers, target, start + 1, end, sum + numbers[start+1]);
        dfs(numbers, target, start + 1, end, sum - numbers[start+1]);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int s = numbers.size();
    dfs(numbers, target, 0, s-1, numbers[0]);
    dfs(numbers, target, 0, s-1, -numbers[0]);
    
    return cnt;
}