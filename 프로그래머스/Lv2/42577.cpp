#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> s;

int cmp(string a, string b){
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
    int book_s = phone_book.size();
    if(book_s == 1) return true;
    
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    int min_len = 1e9;   
    for(int i=0;i<book_s;i++){
        min_len = std::min(min_len, int(phone_book[i].length()));
        
        for(int j=min_len;j<=phone_book[i].length();j++){
            string tmp = phone_book[i].substr(0, j);
            if(s.count(tmp) == 1){
                return false;
            }
        }
        
        s.insert(phone_book[i]);
    }
    
    return answer;
}