#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    // 걸리는 최소, 최대 시간
    long long left = (long long)times[0];
    long long right = (long long)times.back() * n;

    // mid 시간 동안 전부 심사할 수 있는지 확인하면서 탐색
    while(left <= right){
        long long mid = (left + right) / 2;

        long long cnt = 0; // 검사한 사람 수
        for(int time: times){
            cnt += mid/time;
        }

        if(cnt >= n){
            answer = mid;
            right = mid - 1;
        }  
        else{
            left = mid + 1;
        }

    }

    return answer;
}