#include <string>
#include <vector>

using namespace std;

vector<int> students;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    
    students.resize(n + 1, 1); // 1 ~ n
    
    int s = lost.size();
    for(int i=0;i<s;i++){
        students[lost[i]]--;
    }
    s = reserve.size();
    for(int i=0;i<s;i++){
        students[reserve[i]]++;
    }
    
    for(int i=1;i<=n;i++){
        // check left
        if(i > 1 && students[i] == 2 && students[i-1] == 0){
            students[i-1]++;
        }
        else if(i < n && students[i] == 2 && students[i+1] == 0){
            students[i+1]++;
        }
    }
    
    for(int i=1;i<=n;i++){
        if(students[i] == 0)
            answer--;
    }
    
    return answer;
}