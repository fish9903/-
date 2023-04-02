#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<int> graph[20002];
int visit[20002] = { 0, };
int max_dist = 0; // max distance
int max_node_n = 0; // 가장 멀리 있는 노드들의 개수
unordered_map<int, int> m; // <distance, nodes의 개수>

void bfs(int start){
    int i, s;
    queue<pii> q;
    q.push({start, 0});
    visit[start] = 1;
    
    while(!q.empty()){
        int now = q.front().first;
        int dist = q.front().second;
        
        m[dist]++;
        
        max_dist = std::max(max_dist, dist);
        
        q.pop();
        
        s = graph[now].size();
        for(i=0;i<s;i++){
            int flag = 1;
            if(visit[graph[now][i]] == 0){
                q.push({graph[now][i], dist + 1});
                visit[graph[now][i]] = 1;
                flag = 0;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {    
    int i, j;
    int s = edge.size();
    for(i=0;i<s;i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    // bfs
    bfs(1);
    
    return m[max_dist];
}