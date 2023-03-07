#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {    
    vector<int> answer;
    
    if(n > s){
        return {-1};
    }
    
    int div = n;
    for(int i=0;i<n;i++){
        int a = s/div;
        answer.push_back(a);
        
        s -= a;
        div--;
    }
    
    
    sort(answer.begin(), answer.end());
    return answer;
}