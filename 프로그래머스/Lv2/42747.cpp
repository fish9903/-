#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.rbegin(), citations.rend());
    if(citations[0] == 0) return 0;
    
    int s = citations.size();    
    // int h = s;
    // for(;h>=0;h--){
    //     if(citations[h-1] < h) continue;
    //     else return h;
    // }
    
    // binary search
    int start = 0;
    int end = s-1;
    int mid;
    int h = 0;
    while(1){
        if(start > end)
            break;
        mid = (start + end) / 2;
        
        if(citations[mid] >= mid + 1){
            start = mid + 1;
            h = std::max(h, mid + 1);
        }
        else{
            end = mid - 1;
        }
    }
    
    return h;
}