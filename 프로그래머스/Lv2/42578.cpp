#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um; // <name, count>

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int i=0;i<clothes.size();i++){
        um[clothes[i][1]]++;
    }
    
    for(unordered_map<string, int>::iterator iter=um.begin();iter!=um.end(); iter++){
        answer *= (iter->second + 1);
    }
    
    return answer-1;
}