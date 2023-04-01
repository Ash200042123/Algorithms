

#include <iostream>
#include<vector>
#include<climits>

using namespace std;

int MinSmoke(vector<int>& colors, vector<int>& smoke, int n) {
    vector<vector<int>> M(n, vector<int>(n, 0));

    smoke = colors;

    for (int len = 2; len < n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k + 1][j] + smoke[i] * smoke[k + 1] * smoke[j + 1];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    smoke[i] = (smoke[i] + smoke[k + 1]) % 100;
                }
            }
        }
    }

    return M[0][n - 1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> colors(n);
    vector<int> smoke(n);

    for (int i = 0; i < n; i++) {
        cin >> colors[i];
        smoke[i] = colors[i];
    }


	cout << "Minimum smoke is " << MinSmoke(colors,smoke,n);
	return 0;
}


