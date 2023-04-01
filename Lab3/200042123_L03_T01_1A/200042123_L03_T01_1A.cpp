
#include <iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main()
{
	int numCourses;

	cin >> numCourses;
	int numCoursesCopy = 0;
	int numCoursesCopy2 = numCourses;

	vector<vector<int>> prerequisites{ {1,0},{2,0} };

	/*while (numCoursesCopy < numCourses) {
		int a, b;
		cin >> a >> b;
		prerequisites[a].push_back(b);
		numCoursesCopy++;
	}*/

	vector<vector<int>> adjacency(numCourses);
	vector<int> degree(numCourses);
	vector<int> order;
	queue<int> visited;

	for (auto i : prerequisites) {
		adjacency[i[1]].push_back(i[0]);
		degree[i[0]]++;
	}
	
	for (int i = 0;i < numCourses;i++) {
		if (degree[i] == 0) {
			visited.push(i);
		}
	}

	while (!visited.empty()) {
		int x = visited.front();
		visited.pop();
		order.push_back(x);
		numCoursesCopy2--;

		for (auto i : adjacency[x]) {
			if(degree[i]==1){
				visited.push(i);
			}
		}
	}

	if (numCoursesCopy2 != 0) {
		cout << " ";
	}
	else {
		for (auto i : order) {
			cout << i << " ";
		}
	}
	return 0;
}

