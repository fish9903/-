#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define pii pair<int, int>
#define psi pair<string, int>

using namespace std;

bool cmp(psi a, psi b){
    return a.second > b.second;
}
struct pq_cmp{
    bool operator()(pii a, pii b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        else{
            return a.first < b.first;
        }
    }  
};

priority_queue<pii, vector<pii>, pq_cmp> pq[10001]; // <count, index>
map<string, int> sum_m; // <genre, sum>
map<string, priority_queue<pii, vector<pii>, pq_cmp>> m; // <genre, priority queue>


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int s = genres.size();
    int i;
    for(i=0;i<s;i++){
        m[genres[i]].push({plays[i], i});
        sum_m[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> sum_v(sum_m.begin(), sum_m.end());
    sort(sum_v.begin(), sum_v.end(), cmp);
    
    int ss = sum_v.size();
    for(i=0;i<ss;i++){
        priority_queue<pii, vector<pii>, pq_cmp> target = m[sum_v[i].first];
        int qs = target.size();
        if(qs == 1) answer.push_back(target.top().second);
        else{
            int repeat = 2;
            while(repeat--){
                answer.push_back(target.top().second);
                target.pop();
            }
        }
    }
    
    return answer;
}