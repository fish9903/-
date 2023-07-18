#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int x, y; // x: 세로 길이, y: 가로 길이
    for(int i=1;i<=yellow;i++){
        if(yellow % i == 0){
            x = i;
            y = yellow / i;
            
            if(x*y + 2*x + 2*y + 4 == brown + yellow){
                answer.push_back(y+2);
                answer.push_back(x+2);
                break;
            }
        }
    }
    
    return answer;
}