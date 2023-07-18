#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(int k, vector<vector<int>> d, vector<int> t){
    int result = 0;
    int s = d.size();
    for(int i=0;i<s;i++){
        if(k <= 0)
            break;
        if(d[t[i]][0] <= k){
            k -= d[t[i]][1];
            result++;
        }
    }
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    int s = dungeons.size();
    vector<int> temp;
    for(int i=0;i<s;i++)
        temp.push_back(i);
    
    do{
        answer = std::max(answer, calculate(k, dungeons, temp));
    }while(next_permutation(temp.begin(), temp.end()));
    
    return answer;
}