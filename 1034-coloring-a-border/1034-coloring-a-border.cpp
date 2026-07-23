class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    bool checkNeighbors(int i, int j, vector<vector<int>>& grid, int orig){
        int m = grid.size(), n = grid[0].size();
        if(!isValid(i-1,j,m,n) || grid[i-1][j] != orig)return true;
        if(!isValid(i,j+1,m,n) || grid[i][j+1] != orig)return true;
        if(!isValid(i+1,j,m,n) || grid[i+1][j] != orig)return true;
        if(!isValid(i,j-1,m,n) || grid[i][j-1] != orig)return true;
        return false;
    }
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& connectedCompIndices, int m, int n, int orig){
        if(!isValid(i,j,m,n) || grid[i][j] != orig || connectedCompIndices[i][j] == 0)return;
        connectedCompIndices[i][j] = 0;
        dfs(i-1,j,grid,connectedCompIndices,m, n,orig);
        dfs(i,j+1,grid,connectedCompIndices,m, n,orig);
        dfs(i+1,j,grid,connectedCompIndices,m, n,orig);
        dfs(i,j-1,grid,connectedCompIndices,m, n,orig);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        int orig = grid[row][col];
        vector<vector<int>> connectedCompIndices(m, vector<int>(n, -1));
        dfs(row, col, grid, connectedCompIndices, m, n, orig);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!connectedCompIndices[i][j] && checkNeighbors(i,j,grid,orig)){
                    connectedCompIndices[i][j] = color;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(connectedCompIndices[i][j] == -1 || connectedCompIndices[i][j] == 0){
                    connectedCompIndices[i][j] = grid[i][j];
                }
            }
        }
        return connectedCompIndices;
    }
};