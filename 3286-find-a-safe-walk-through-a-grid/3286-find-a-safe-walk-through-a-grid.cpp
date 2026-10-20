class Solution {
public:
    int dp[51][51][101];
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    bool find (int i, int j, auto& grid, int health, int m, int n, auto&vis) {
        if(!isValid(i,j,m,n) || health < 1 || vis[i][j])return false;
        if(i == m-1 && j == n-1){
            if(grid[i][j])health--;
            return health >= 1;
        }
        if(dp[i][j][health] != -1)return dp[i][j][health];

        vis[i][j] = true;
        bool n1, n2; n1 = n2 = false;

        if(!grid[i][j]) {
            n1 = find(i-1,j,grid,health,m,n,vis) || find(i,j+1,grid,health,m,n,vis) || find(i+1,j,grid,health,m,n,vis) || find(i,j-1,grid,health,m,n,vis);
        }
        else {
            n2 = find(i-1,j,grid,health-1,m,n,vis) || find(i,j+1,grid,health-1,m,n,vis) || find(i+1,j,grid,health-1,m,n,vis) || find(i,j-1,grid,health-1,m,n,vis);
        }

        if(n1 || n2)return dp[i][j][health] = true;
        vis[i][j] = false;
        return dp[i][j][health] = false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        memset(dp, -1, sizeof(dp));
        return find(0, 0, grid, health, m, n, vis);
    }
};