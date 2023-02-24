#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {    
    int i, j;
    int ws = words.size();
    int qs = queries.size();
    vector<int> answer(qs);
    vector<string> wordSize[10001]; // word의 길이에 따라 나눠 저장
    vector<string> rwordSize[10001]; // reverse

    for(i = 0; i < ws; i++){
        wordSize[words[i].size()].push_back(words[i]);
        reverse(words[i].begin(), words[i].end());
        rwordSize[words[i].size()].push_back(words[i]);
    }
    for(i = 0; i < 10001; i++){
        sort(wordSize[i].begin(), wordSize[i].end());
        sort(rwordSize[i].begin(), rwordSize[i].end());
    }

    for(i = 0; i < qs; i++) {
        string pattern = "";
        int l = queries[i].length();

        for(j = 0; j < l; j++) {
            if(queries[i][j] != '?') pattern += queries[i][j];
        }

        if(queries[i][0] == '?'){ // prefix
            reverse(pattern.begin(), pattern.end());
        }

        string firstPattern = pattern; // aa
        string secondPattern = pattern; // zz
        for(j = 0; j < l - pattern.length(); j++){
            firstPattern += 'a';
            secondPattern += 'z';
        }

        // firstPattern ~ secondPattern
        int low, high, cnt;
        if(queries[i][0] != '?') { // postfix
            low = lower_bound(wordSize[l].begin(), wordSize[l].end(), firstPattern) - wordSize[l].begin();
            high = upper_bound(wordSize[l].begin(), wordSize[l].end(), secondPattern) - wordSize[l].begin(); 
        }
        else { // prefix
            // rwordSize[l]            
            low = lower_bound(rwordSize[l].begin(), rwordSize[l].end(), firstPattern) - rwordSize[l].begin();
            high = upper_bound(rwordSize[l].begin(), rwordSize[l].end(), secondPattern) - rwordSize[l].begin();
        }
        cnt = high - low;
        answer[i] = cnt;
    }

    return answer;
}