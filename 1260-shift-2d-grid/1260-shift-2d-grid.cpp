class Solution {
public:
    void shift(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        int lastEle = grid[m-1][n-1];
        int i = m-1;
        while(i >= 1){
            int j = n-1;
            while(j >= 1){
                grid[i][j] = grid[i][j-1];
                j--;
            }
            grid[i][0] = grid[i-1][n-1];
            i--;
        }
        int j = n-1;
        while(j >= 1){
            grid[0][j] = grid[0][j-1];
            j--;
        }
        grid[0][0] = lastEle;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        while(k--){
            shift(grid);
        }
        return grid;
    }
};