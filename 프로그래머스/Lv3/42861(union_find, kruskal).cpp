// union find

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[102];

int FindParent(int a){
    if(parent[a] != a){
        parent[a] = FindParent(parent[a]);
    }
    return parent[a];
}

int Union(int a, int b){
    a = FindParent(a);
    b = FindParent(b);

    if(a < b){
        parent[b] = a;
        return 1;
    }
    else if(a > b){
        parent[a] = b;
        return 1;
    }
    return 0;
}

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for(int i=0;i<n;i++) parent[i] = i;

    sort(costs.begin(), costs.end(), cmp);

    for(int i=0;i<costs.size();i++){
        if(FindParent(costs[i][0]) != FindParent(costs[i][1])){
            Union(costs[i][0], costs[i][1]);
            answer += costs[i][2];
        }
    }

    // for(int i=0;i<n;i++)
    //     cout << parent[i] <<endl;

    return answer;
}