#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int i, j;
    int s = stations.size();
    
    if(s == n || s-1 == n) return 0;
    
    // 구역 나누기
    // w가 0인 station이 0, n+1 index에 있다고 가정
    vector<pair<int, int>> area;
    int left, right;
    
    // 0
    left = 1;
    right = stations[0] - w - 1;
    if(left <= right){
        area.push_back({left, right});
    }
    // s-1
    left = stations[s-1] + w + 1;
    right = n;
    if(left <= right){
        area.push_back({left, right});
    }
    
    for(i=1;i<s;i++){
        left = stations[i-1] + w + 1;
        right = stations[i] - w - 1;
        
        if(left <= right){
            area.push_back({left, right});
        }
    }
    
    s = area.size();
    int diff;
    int width = 2*w+1;
    for(i=0;i<s;i++){
        diff = area[i].second - area[i].first + 1;
        answer += (int)ceil((double)diff/(double)width);
    }
    
    return answer;
}