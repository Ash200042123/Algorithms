
#include <iostream>
#include<vector>
#include<map>

using namespace std;

void dfs(int node, vector<pair<int,int>> adj[], vector<int> ls) {
	
	int visited[10] = { 0 };
	visited[node] = 1;
	ls.push_back(node);

	for (auto it : adj[node].front().first) {
		if (!visited[it]) {
			dfs(it, adj, ls);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> adj[100];

	for (int i = 0;i < m;i++) {
		int x, y, z;

		cin >> x >> y >> z;

		adj[x].push_back({ y,z });
		adj[y].push_back({ x,z });
	}
}

