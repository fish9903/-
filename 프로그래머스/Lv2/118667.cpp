#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer1 = 0, answer2 = 0;
    
    // q3 = q1 + q2;
    vector<int> q3;
    q3.insert(q3.begin(), queue1.begin(), queue1.end());
    q3.insert(q3.end(), queue2.begin(), queue2.end());
    
    // q4 = q2 + q1;
    vector<int> q4;
    q4.insert(q4.begin(), queue2.begin(), queue2.end());
    q4.insert(q4.end(), queue1.begin(), queue1.end());
    
    // sum
    long long q_sum = 0, q1_sum = 0, q2_sum = 0;
    for(int i=0;i<q3.size();i++){
        q_sum += q3[i];
        
        if(i<queue1.size()) q1_sum += q3[i];
        else q2_sum += q3[i];
    }
    long long target_sum = q_sum / 2;

    // case: q3
    int left = 0, right = queue1.size() - 1;
    long long t_sum = q1_sum;
    while(1){
        if(t_sum == target_sum){
            break;
        }
        else if(t_sum < target_sum){
            right++;
            if(right>q3.size()){
                answer1 = -1;
                break;
            }
            
            t_sum += q3[right];
            answer1++;
        }
        else{
            left++;
            if(left>right){
                answer1 = -1;
                break;
            }
            
            t_sum -= q3[left - 1];
            answer1++;
        }
    }
    
    cout << left << ' ' << right << endl;
    
    // case: q4
    left = 0, right = queue2.size() - 1;
    t_sum = q2_sum;
    while(1){
        if(t_sum == target_sum){
            break;
        }
        else if(t_sum < target_sum){
            right++;
            if(right>q4.size()){
                answer2 = -1;
                break;
            }
            
            t_sum += q4[right];
            answer2++;
        }
        else{
            left++;
            if(left>right){
                answer2 = -1;
                break;
            }
            
            t_sum -= q4[left - 1];
            answer2++;
        }
    }
    
    cout << left << ' ' << right << endl;
    
    if(answer1 == -1 || answer2 == -1){
        return std::max(answer1, answer2);
    }
    else{
        return std::min(answer2, answer2);
    }
    
    return answer1;
}