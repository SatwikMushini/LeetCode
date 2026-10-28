class Solution {
public:
    int solve(int i, int j, int xori, auto& grid, int m, int n, auto& dp) {
        if(i >= m || j >= n)return INT_MAX;
        xori ^= grid[i][j];
        if(i == m-1 && j == n-1)return xori;
        if(dp[i][j][xori] != -1)return dp[i][j][xori];
        int n1 = solve(i+1, j, xori, grid, m, n, dp);
        int n2 = solve(i, j+1, xori, grid, m, n, dp);
        return dp[i][j][xori] = min(n1, n2);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return solve(0, 0, 0, grid, m, n, dp);
    }
};