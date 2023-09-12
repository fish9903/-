#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parent; // <child, parent>
unordered_map<string, int> profit; // <name, profit>

void UpdateProfit(string name, int money) {
    if (name == "-"){
        int share = money * 0.1; // give parent

        profit[name] += (money - share);
    }
    else{
        int share = money * 0.1; // give parent

        profit[name] += (money - share);
        if (share < 1) return;

        UpdateProfit(parent[name], share); 
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    // init
    for(int i=0;i<enroll.size();i++){
        parent[enroll[i]] = referral[i];
    }
    
    // for(int i=0;i<seller.size();i++){
    //     profit[seller[i]] = amount[i] * 100;
    // }
    // -----------
    
    for(int i=0;i<seller.size();i++){
        UpdateProfit(seller[i], amount[i] * 100);
    }
    
    for (int i = 0; i < enroll.size(); ++i)
        answer.push_back(profit[enroll[i]]);
    
    return answer;
}