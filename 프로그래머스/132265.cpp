#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;    
    int s = topping.size();
    vector<pair<int,int>> LeftRight(s);
    set<int> left;
    set<int> right;
    for(int i=0;i<s-1;i++){
        left.insert(topping[i]);
        LeftRight[i].first = left.size();
    }
    for(int i=s-1;i>=1;i--){
        right.insert(topping[i]);
        LeftRight[i-1].second = right.size();
    }
    for(int i=0;i<s-2;i++){
        if(LeftRight[i].first == LeftRight[i].second) answer++;
    }
    
    return answer;
}