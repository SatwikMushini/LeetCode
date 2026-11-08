class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0, cnt = 0;
        for(int i = 0; i < m; i++) {
            int rows = 0, jj = -1;
            for(int j = 0; j < n; j++) {
                if(grid[i][j]){
                    rows++; ans++; jj = j;
                }
            }
            if(rows == 1){
                int found = 0;
                for(int k = 0; k < m; k++){
                    if(grid[k][jj]){
                        found++;
                    }
                }
                cnt += (found == 1);
            }
        }
        return ans - cnt;
    }
};