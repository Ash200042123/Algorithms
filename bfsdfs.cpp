class Solution {
    private:
    void bfs(int row, int col, vector<vector<int>> &visited,vector<vector<char>>& grid ){
        int n= grid.size();
        int m= grid[0].size();
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            int r=q.front().first();
            int c=q.front().second();
            q.pop();

            for(int i=r-1;i<=r+1;i++){
                for(int j=c-1;j<=c+1;j++){
                    if(i>=0 && j>=0 && i<n && j<m && !visited[i][j] && grid[i][j]=='1'){
                        visited[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        int count=0;

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]=='1' && !visited[row][col]){
                    count++;
                    bfs(row,col,visited,grid);
                }
            }
        }
        return count;
    }
};