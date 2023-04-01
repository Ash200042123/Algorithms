
#include <iostream>
#include<vector>
#include<map>

using namespace std;


int getWays(int change, vector<int> available) {

	int count = 0;
	//int mn = 0;

	for (int i = 0;i < available.size();i++) {

		if (change - available.at(i) < 0) {
			return 0;
		}
		else if (change - available.at(i) == 0) {
			return 1;
		}
		else {
			count += getWays(change - available.at(i), available);
		}
	}
	return count;
}



int main()
{
	int n, m;
	vector<int> c;

	cin >> n>>m;

	for (int i = 0;i < m;i++) {
		int x;
		cin >> x;

	}
	cout << getWays(n, c) << endl;
	//cout << count << endl;
	return 0;
}

