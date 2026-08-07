class Solution {
public:
    bool check(int i, int j, int peak, vector<vector<int>>& grid, vector<vector<int>>& vis, int n){
        if(i == n-1 && j == n-1)return true;
        if(i >= n || j >= n || i < 0 || j < 0)return false;
        if(vis[i][j] || grid[i][j] > peak)return false;

        vis[i][j] = 1;
        if(check(i-1, j, peak ,grid, vis, n) || check(i, j+1, peak, grid, vis, n) || check(i+1, j, peak, grid, vis, n) || check(i, j-1, peak, grid, vis, n)) return true;

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = max(grid[0][0], grid[n-1][n-1]), high = grid[n-1][n-1];
        for(auto x : grid){
            high = max(high, *max_element(x.begin(), x.end()));
        }

        while(low <= high){
            int mid = low + (high - low) / 2;
            vector<vector<int>> vis(n, vector<int>(n, 0));
            if(check(0, 0, mid, grid, vis, n)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};