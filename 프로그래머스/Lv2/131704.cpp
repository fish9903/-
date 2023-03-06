#include <string>
#include <vector>
#include <stack>

using namespace std;
int answer;
stack<int> belt;

int solution(vector<int> order) {
    int i = 0;
    int s = order.size();
    for (int j = 1; j <= s; j++) {
        if (order[i] != j) {
            belt.push(j);
            continue;
        }
        else { // order[i] == j
            i++;
            answer++;

            while (!belt.empty() && belt.top() == order[i] && i < s) {
                answer++;
                i++;
                belt.pop();
            }
        }
    }
    return answer;
}