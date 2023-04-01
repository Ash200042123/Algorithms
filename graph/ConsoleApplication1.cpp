
#include <iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> bfsofGraph(int v, vector<int> adj[]) {
	vector<int> bfs;
	int visited[10] = { 0 };
	visited[0] = 1;

	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		bfs.push_back(node);

		for (auto it : adj[node]) {
			if (visited[it] != 1) {
				visited[it] = 1;
				q.push(it);
			}
		}
	}
	return bfs;
}


void dfs(int node, vector<int> adj[], int visited[], vector<int>& ls) {
	visited[node] = 1;
	ls.push_back(node);

	for (auto it : adj[node]) {
		if (!visited[it]) {
			dfs(it, adj, visited, ls);
		}
	}
}

vector<int> dfsofGraph(int v, vector<int> adj[]) {
	int visited[10] = { 0 };
	int start = 0;
	vector<int> ls;

	dfs(start, adj, visited, ls);
	return ls;
}



int main()
{
	int n, m;
	vector<int> adj[6];
	cin >> n>>m;

	for (int i = 0;i < m;i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	return 0;
}

