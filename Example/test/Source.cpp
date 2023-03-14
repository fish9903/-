#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int Astart = 0, Bstart = 0;
    int end = A.size();

    while (Astart < end && Bstart < end) {
        int a = A[Astart];
        int b = B[Bstart];

        while (a > b) {
            Bstart++;
            if (Bstart == end) {
                break;
            }
            b = B[Bstart];
        }
        if (a < b) {
            answer++;
            Astart++;
            Bstart++;
        }
    }

    return answer;
}

int main() {
    solution({ 2,2,2,2 }, { 2,2,2,2 });
    return 0;
}