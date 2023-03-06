#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> answer;

// [start, end)
int getSum(vector<int> elements, int start, int end){
    int sum = 0;
    int s = elements.size();
    int i, index = start;
    for(i=0;i<end - start;i++, index++){
        if(index >= s) index %= s;
        sum += elements[index];
    }
    return sum;
}

int solution(vector<int> elements) {
    
    int i, j;
    int s = elements.size();
    int sum;
    for(i=1;i<=s;i++){
        for(j=0;j<s;j++){
            sum = getSum(elements, j, j+i);
            answer.insert(sum);
        }
    }
    
    return answer.size();
}