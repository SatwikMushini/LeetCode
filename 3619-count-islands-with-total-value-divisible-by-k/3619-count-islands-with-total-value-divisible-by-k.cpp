typedef long long ll;
class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    ll dfs(int i, int j, auto& grid, auto& vis, int m, int n) {
        if(!isValid(i,j,m,n) || !grid[i][j] || vis[i][j])return 0;
        vis[i][j] = true;
        ll sum = 1ll * grid[i][j] + dfs(i+1,j,grid,vis,m,n) + dfs(i,j-1,grid,vis,m,n) + dfs(i-1,j,grid,vis,m,n) + dfs(i,j+1,grid,vis,m,n);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !vis[i][j]){
                    // int sum = dfs(i, j, grid, vis, m, n); cout << sum << " ";
                    cnt += ((dfs(i, j, grid, vis, m, n) % (1ll*k)) == 0);
                }
            }
        }
        return cnt;
    }
};