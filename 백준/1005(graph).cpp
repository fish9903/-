#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--) {
        int N, K, W;
        int delay[1002];
        int pre[1002] = { 0, };
        vector<int> next[1002];
        cin >> N >> K;
        for (int i = 1; i <= N; i++) cin >> delay[i];
        for (int i = 0; i < K; i++) {
            int start, dest;
            cin >> start >> dest;
            next[start].push_back(dest);
            pre[dest]++;
        }
        cin >> W;

        int time[1002] = { 0, };
        queue<int> q;
        for (int i = 1; i <= N; i++) 
            if (pre[i] == 0) q.push(i);

        while (pre[W] > 0) {
            int before = q.front();
            //if (before == W && pre[W] == 0) break;
            q.pop();
            
            for (int i = 0; i < next[before].size(); i++) {
                time[next[before][i]] = max(time[next[before][i]], time[before] + delay[before]);

                pre[next[before][i]]--;
                if (pre[next[before][i]] == 0) q.push(next[before][i]);
            }
        }
        
        cout << time[W] + delay[W] << '\n';
    }
}