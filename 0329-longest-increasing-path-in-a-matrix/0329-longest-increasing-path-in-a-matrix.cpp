class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int dfs(int i, int j, vector<vector<int>>& matrix, int m, int n, vector<pair<int,int>> &dir, vector<vector<int>> &dp){
        if(dp[i][j] != -1)return dp[i][j];
        int maxPath = 1;
        for(auto &[x,y]: dir){
            if(isValid(i+x, j+y, m, n) && matrix[i+x][j+y] > matrix[i][j]){
                maxPath = max(maxPath, 1 + dfs(i+x, j+y, matrix, m, n, dir, dp));
            }
        }
        return dp[i][j] = maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxPath = 1;

        vector<vector<int>>dp(m, vector<int>(n, -1));
        vector<pair<int,int>>dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxPath = max(maxPath, dfs(i,j,matrix, m, n, dir, dp));
            }
        }

        return maxPath;
    }
};