// union find 에서 주의할 것
// 1. parent 설정 기준을 명확히 할 것
// 2. parent 배열 완성 후, 이를 직접 사용하지 말고 findParent(parent[i]) 또는 findParent(i)로 계산할 것(parent 배열은 참고용)
// 데이터를 처리하는 과정에서 연결되었지만 처리가 안될 경우도 있기 때문
// 백준 1043 거짓말 파티 참고

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> answer;
vector<int> parent;

int findParent(int a) {
	if (parent[a] != a) {
		parent[a] = findParent(parent[a]);
	}
	return parent[a];
}

bool merge(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return false;
    
    if(a<b) parent[b] = a;
    else parent[a] = b;
	//parent[b] = a;
	return true;
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0;i<n;i++) parent.push_back(i);
    
    // union find
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i != j && computers[i][j] == 1)
                merge(i, j);
        }
    }
    
    //for(int i=0;i<n;i++) cout << parent[i] << endl;
    
    for(int i=0;i<n;i++){
        answer.insert(findParent(i));
    }
    
    return answer.size();
}