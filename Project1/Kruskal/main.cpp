#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
int parent[10000 + 1];
vector<pair<int, pair<int, int>>> edges; // {cost, {node, node}}
int result;

int FindParent(int x) {
	if (parent[x] != x) 
		parent[x] = FindParent(parent[x]); // parent 갱신 필수!!!
	return parent[x];
}

void UnionParent(int a, int b) {
	a = FindParent(a);
	b = FindParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> v >> e;
	for (int i = 1; i <= v; i++) parent[i] = i;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c, {a, b,} }); // cost, node, node
	}
	
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (FindParent(a) != FindParent(b)) {
			int cost = edges[i].first;
			UnionParent(a, b);
			result += cost;
		}
	}

	cout << result << endl;

	for (int i = 1; i <= v; i++)
		cout << parent[i] << ' ';
	cout << endl;

	cout << FindParent(4) << endl << FindParent(7) << endl;

	return 0;
}