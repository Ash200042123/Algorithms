#include<iostream>
using namespace std;

int main() {
    int n;
    int i = 0, j = 0;
    cin >> n;

    int arr[100][100];
    while (i < n) {
        while (j < n) {
            cin >> arr[i][j];
            j++;
        }
        j = 0;
        i++;
    }

    i = 0, j = 0;

    while (i < n) {
        int flag = 1;
        while (j < n) {
            if (arr[i][j] == 1 && i == j) {
                j++;
                continue;
            }
            else if (arr[i][j] == 1 && i != j) {
                flag = 0;
                break;
            }
            j++;
        }
        j = 0;
        if (flag == 1) {
            int k = 0;
            while (k < n) {
                if (arr[k][i] == 0) {
                    flag = 0;
                    break;
                }
                k++;
            }
        }

        if (flag == 1) {
            cout << "Person " << i << " is the celebrity";
            return 0;
        }
        i++;
    }
    cout << "There is no celebrity";
}