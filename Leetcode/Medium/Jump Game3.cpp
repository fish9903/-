class Solution {
public:
    queue<int> q; // index
    vector<int> visited;

    bool bfs(vector<int>& arr, int start){
        if(arr[start] == 0) return true;

        int n = arr.size();
        q.push(start);
        visited[start] = 1;

        while(!q.empty()){
            int x = q.front(); // current index
            q.pop();

            // check 0 in range
            int next = x + arr[x];
            if(next < n && visited[next] == 0){
                if(arr[next] == 0) return true;
                q.push(next);
                visited[next] = 1;
            }

            next = x - arr[x];
            if(next >= 0 && visited[next] == 0){
                if(arr[next] == 0) return true;
                q.push(next);
                visited[next] = 1;
            }
        }

        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        visited.resize(arr.size(), 0);
        return bfs(arr, start);
    }
};