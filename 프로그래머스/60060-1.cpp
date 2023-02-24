#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    map<string,int> m; // queries, cnt
    for(string& s:queries)
        m[s]=0;

    for(string& s:words){
        string pre=s;
        // prefix
        for(int i=0;i<pre.length();++i){
            
            pre[i]='?';
            if(m.find(pre)!=m.end()) // find
                m[pre]++;
        }
        // postfix
        pre=s;
        for(int i=pre.length()-1;i>0;i--){
            pre[i]='?';
            if(m.find(pre)!=m.end()) // find
                m[pre]++;
        }
    }

    for(string& s:queries)
        answer.push_back(m[s]);

    return answer;
}