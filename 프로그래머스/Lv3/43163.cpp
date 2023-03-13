#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define psi pair<string,int> // word, count

using namespace std;
int Min = 1e9;
vector<int> visited;

bool canConvert(string a, string b){
    int diff = 0;
    for(int i=0;i<a.length();i++){
        if(a[i] != b[i]) diff++;
        if(diff == 2) return false;
    }
    return true;
}

void bfs(vector<string> words, string begin, string target){
    queue<psi> q;
    q.push({begin, 0});
    
    while(!q.empty()){
        string w = q.front().first;
        int c = q.front().second;
        if(w == target){
            Min = std::min(Min, c);
        }
        q.pop();
        
        int s = words.size();
        for(int i=0;i<s;i++){
            if(visited[i] == 0 && canConvert(w, words[i])){
                q.push({words[i], c+1});
                visited[i] = 1;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    visited.resize(words.size());
    
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    
    bfs(words, begin, target);
    
    answer = Min;
    return answer;
}