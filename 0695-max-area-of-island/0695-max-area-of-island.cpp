class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int giveMaxArea(int r, int c, auto& grid, int m, int n){
        if(!isValid(r,c,m,n) || grid[r][c] == 0)return 0;
        grid[r][c] = 0;
        return 1 + giveMaxArea(r-1,c,grid,m,n) + giveMaxArea(r,c+1,grid,m,n) + giveMaxArea(r+1,c,grid,m,n) + giveMaxArea(r,c-1,grid,m,n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, giveMaxArea(i, j, grid, m, n));
                }
            }
        }
        return maxArea;
    }
};