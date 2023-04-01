
#include <iostream>
#include<vector>
#include<queue>

using namespace std;

bool bfsofGraph(int v, vector<int> adj[]) {
	vector<int> bfs;
	int visited[10] = { 0 };
	int color[10] = { 0 };
	visited[0] = 1;
	int counter = 0;
	bool flag = true;

	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		bfs.push_back(node);

		for (auto it : adj[node]) {

			if (visited[it]) {
				if (color[it]==4 && counter%2==1) {
					flag = false;
				}
				if (color[it] == 5 && counter % 2 == 0) {
					flag = false;
				}
			}
			if (visited[it] != 1) {
				
				visited[it] = 1;

				if (counter % 2 == 0) color[it] = 4;
				else color[it] = 5;
				q.push(it);
			}
		}
		counter++;
	}
	return flag;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> adj[100];

	for (int i = 0;i < m;i++) {
		int x, y;

		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	bool colorable = bfsofGraph(n, adj);

	if(colorable) cout << "BICOLORABLE" << endl;
	else cout << "NOT BICOLORABLE" << endl;
}

