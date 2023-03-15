#include <string>
#include <vector>

using namespace std;

// n: 구역의 개수, m: 롤러의 폭, section: 칠해야할 곳(번호)
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    if(n == m) return 1;
    
    int start_pos = section[0];
    answer++;
    
    int s = section.size();
    for(int i=1;i<s;i++){ // i: index of section
        if(section[i] < start_pos + m) 
            continue;
        answer++;
        start_pos = section[i];
    }
    
    return answer;
}