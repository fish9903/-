#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int win_count = 0, i, j;
    i = 0;
    for (j=0;j<B.size();j++){
        if (A[i] < B[j])
        {
            i++;
            win_count++;
        }
    }
    return win_count;
}