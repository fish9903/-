#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] != b[0]) return a[0] > b[0];
    else return a[1] < b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int maxScore = 0;
    pair<int, int> ho = {scores[0][0], scores[0][1]};
    
    sort(scores.begin(), scores.end(), cmp);
    
    int s = scores.size();
    for(int i=0;i<s;i++){
        if(scores[i][1] < maxScore){
            if(scores[i][0] == ho.first && scores[i][1] == ho.second) return -1;
        }
        else{
            maxScore = std::max(maxScore, scores[i][1]);
            if(scores[i][0] + scores[i][1] > ho.first + ho.second) answer++;
        }
    }
    
    return answer;
}