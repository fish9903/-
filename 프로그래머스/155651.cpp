#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ToInt(string s){
    s.erase(2, 1);
    return stoi(s);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<pair<int, int>> v(book_time.size());
    vector<int> valid(book_time.size(), 1); // 1: valid
    
    for(int i=0;i<book_time.size();i++){
        int s = ToInt(book_time[i][0]);
        int e = ToInt(book_time[i][1]) + 10;
        if(e%100 >= 60) {
            e = e + 40;
        }             
        if(e/100 >= 24) {
            e = 2400;
        }
        v[i] = {s, e};
    }
    sort(v.begin(), v.end());
    
    // connect
    for(int i=0; i<v.size()-1; i++){
        int end = v[i].second;
        for(int j=i+1; j<v.size(); j++){
            if(v[j].first >= end && valid[j] == 1 && valid[i] == 1){
                end = v[j].second;
                valid[j] = 0; // invalid
            }
        }
    }
    
    for(int i=0; i<valid.size(); i++){
        if(valid[i]) {
            answer++;
        }
    }
    
    return answer;
}