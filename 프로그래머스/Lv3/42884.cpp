#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int s = routes.size();
    
    sort(routes.begin(), routes.end(), cmp);
    
    int end = routes[0][1];
    for(int i=1;i<s;i++){
        if(routes[i][0] > end){
            answer++;
            end = routes[i][1];
        }
        if(routes[i][1] < end){
            end = routes[i][1];
        }
    }
    answer++;
    return answer;
}