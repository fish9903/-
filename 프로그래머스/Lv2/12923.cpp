#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long getNum(long long a){
    long long max = 1;
    for(long long i=2;i<=sqrt(a) && i<=10000000;i++){
        if(a % i == 0){
            int div = a/i;
            if(div <= 10000000) return div;
            max = i;
        }
    }
    return max;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end-begin+1,0);
    
    int start = 0;
    for(long long i = begin; i<= end; i++, start++){
        if(i!=1){
            int num = getNum(i);
            answer[start]=(getNum(i));
        }
    }
    
    return answer;
}