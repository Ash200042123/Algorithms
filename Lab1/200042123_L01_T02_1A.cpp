#include<iostream>
#include<vector>
#include<queue>
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

    int visited[100] = 0;
    queue<int> processing;
    int province=0;

    while(i<n){
        visited[i]=1;
        while(j<n){
            if(i==j) {
                j++;
                continue;
                }
            else if(i!=j && arr[i][j]==1){
                visited[j]=1;
                processing.push(j);
            }
            j++;
        }
        j=0;
        while(!processing.empty()){
            int k= processing.front();
            processing.pop();
            visited[k]=1;
            while(j<n){
                if(visited[j]==1 || j==k){
                    j++;
                    continue;
                }
            }
            j=0;
        }
        i++;
    }
}