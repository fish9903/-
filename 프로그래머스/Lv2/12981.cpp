#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

set<string> wordList;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    
    wordList.insert(words[0]);
    
    for(int i=1;i<words.size();i++){
        if(wordList.count(words[i]) == 1 || words[i-1][words[i-1].size()-1] != words[i][0]){
            // 탈락
            cout << words[i] << endl;
            int p = i % n + 1; // 몇 번째 사람            
            int index = i/n + 1;
            
            return {p, index};
        }
        else{
            wordList.insert(words[i]);
        }
    }

    return answer;
}