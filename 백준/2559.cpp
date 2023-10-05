/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // input 
    int N, K;
    cin >> N >> K;
    
    vector<int> v(N, 0);
    
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    // ----
    
    int left = 0, right = K - 1;
    int sum = 0;
    int max_sum = -1e9;
    
    // first
    for(int i=left;i<=right;i++){
        sum += v[i];
    }
    max_sum = sum;
    
    while(1){
        if(right >= N - 1){
            break;
        }
        // move and update
        sum -= v[left];
        left++;
        right++;
        sum += v[right];
        
        if(sum > max_sum){
            max_sum = sum;
        }
    }
    
    cout << max_sum;
    
    return 0;
}
