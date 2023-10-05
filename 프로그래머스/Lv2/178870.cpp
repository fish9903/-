#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int left = 0, right = 0;
    int min_left = 0, min_right = 1e9;
    int s = sequence.size();
    int sum = sequence[0];

    while(right < s && left < s){
        if(sum == k){
            if(right - left < min_right - min_left){
                min_left = left;
                min_right = right;
            }
            
            // reset
            sum -= sequence[left];
            left++;
            right++;
            sum += sequence[right];
        }
        else if(sum < k){
            right++;
            sum += sequence[right];
        }
        else {
            sum -= sequence[left];
            left++;
        }
    }
    
    answer.push_back(min_left);
    answer.push_back(min_right);
    return answer;
}