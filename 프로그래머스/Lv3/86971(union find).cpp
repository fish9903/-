#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[102];
unordered_map<int, int> um;

void initParent(int s){
    for(int i=1;i<=s;i++){
        parent[i] = i;
    }        
}

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

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    int s = wires.size();
    vector<int> temp(s-1, 1);
    temp.push_back(0);
    sort(temp.begin(), temp.end());
    do{        
        vector<vector<int>> temp_wires;
        for(int i=0;i<s;i++){
            if(temp[i] == 1) temp_wires.push_back(wires[i]);
        }
        
        initParent(n);
        for(int i=0;i<temp_wires.size();i++){
            Union(temp_wires[i][0], temp_wires[i][1]);
        }

        for(int i=1;i<=n;i++)
            parent[i] = FindParent(i);


        for(int i=1;i<=n;i++){
            //cout << parent[i];
            um[parent[i]]++;
        }
        //cout << endl;
        
        int result = 0;
        unordered_map<int, int>::iterator iter = um.begin();
        for(;iter != um.end(); iter++){
            if(result == 0) result = iter->second;
            else result -= iter->second;
        }

        answer = std::min(answer, abs(result));
        um.clear();
    }while(next_permutation(temp.begin(), temp.end()));

    
    return abs(answer);
}