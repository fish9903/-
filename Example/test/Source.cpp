#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int arr[1000000 + 1];

void bfs(int x, int y, int n) {
    arr[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (num + n <= 1000000 && num + n <= y && arr[num + n] == 0) {
            arr[num + n] = arr[num] + 1;
            q.push(num + n);
        }
        if (num * 2 <= 1000000 && num * 2 <= y && arr[num * 2] == 0) {
            arr[num * 2] = arr[num] + 1;
            q.push(num * 2);
        }
        if (num * 3 <= 1000000 && num * 3 <= y && arr[num * 2] == 0) {
            arr[num * 3] = arr[num] + 1;
            q.push(num * 3);
        }
    }
}

int solution(int x, int y, int n) {
    int answer = 0;
    fill(arr, arr + 1000001, 0);

    bfs(x, y, n);

    if (arr[y] == 0) return -1;

    return arr[y];
}

int main() {
    cout << solution(10, 40, 5) << endl;
    return 0;
}