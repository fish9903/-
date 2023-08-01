#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    rocks.insert(rocks.begin(), 0); // 시작점 추가
    rocks.push_back(distance);      // 끝점 추가
    
    vector<int> able(rocks.size(), 1);
    
    // 바위 사이의 거리를 이분탐색
    int start = 0;
    int end = distance;
    int mid;
    int cnt;
    int base;
    bool flag;
    
    while(start <= end){
        mid = (start + end) / 2;
        cnt = n;
        flag = true;
        
        //cout << mid << ' ' << start << ' ' << end << endl;
        
        // mid 가능한지 판단
        base = 0;
        for(int i=1;i<rocks.size();i++){
            if(base + mid > rocks[i]){
                if(cnt > 0){
                    cnt--;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else{
                base = rocks[i];
            }
        }
        
        if(flag){
            answer = max(answer, mid);
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    
    return answer;
}