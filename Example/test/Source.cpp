#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

queue<int> q;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    for (int i = 0; i < progresses.size(); i++) q.push(progresses[i]);

    int done = 0;
    int days;
    int i = 0;
    int p = q.front();
    q.pop();

    // 작업 진행 할 일 수
    days = ceil(double(100 - p) / speeds[i]);

    i++;
    done++;

    while (!q.empty()) {
        p = q.front();
        q.pop();
        p += (days * speeds[i]);

        if (p < 100) {
            days += ceil(double(100 - p) / speeds[i]);
            answer.push_back(done);
            done = 0;
        }
        else {
            done++;
        }
        i++;
        cout << days << endl;
    }

    answer.push_back(done);

    return answer;
}

int main() {
    solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 });

    return 0;
}