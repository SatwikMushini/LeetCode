class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        int m = grid.size(), n = grid[0].size();
        if(!isValid(i,j,m,n) ||  vis[i][j] || !grid[i][j])return 0;
        vis[i][j] = true;
        int topSum = grid[i][j] + dfs(i-1, j, grid, vis);
        int rightSum = grid[i][j] +  dfs(i, j+1, grid, vis);
        int bottomSum = grid[i][j] + dfs(i+1, j, grid, vis);
        int leftSum = grid[i][j] + dfs(i, j-1, grid, vis);
        vis[i][j] = false;
        return max(max(topSum, rightSum), max(bottomSum, leftSum));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int maxi = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    maxi = max(maxi, dfs(i, j, grid, vis));
                }
            }
        }
        return maxi;
    }
};