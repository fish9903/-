#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    
    if(s1 == s2) return a < b;
    else return stoi(s1) > stoi(s2);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    for(int i=0;i<numbers.size();i++){
        answer += to_string(numbers[i]);
    }
    
    int index = 0;
    while(answer[index] == '0'){
        index++;
    }
    
    answer = answer.substr(index);
    if(answer == "") return "0";
    
    return answer;
}