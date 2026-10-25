class Solution {
public:
    bool bfs(int i, int j, auto& grid, auto& vis, int m, int n) {
        vis[i][j] = true;
        queue<pair<int,int>>q;
        q.emplace(i,j);
        bool ans = true;
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if(x-1 >= 0 && !grid[x-1][y] && !vis[x-1][y]){
                vis[x-1][y] = true;
                q.emplace(x-1, y);
                if(x-1 == 0)ans = false;
            }
            if(y+1 < n && !grid[x][y+1] && !vis[x][y+1]){
                vis[x][y+1] = true;
                q.emplace(x, y+1);
                if(y+1 == n-1)ans = false;
            }
            if(x+1 < m && !grid[x+1][y] && !vis[x+1][y]){
                vis[x+1][y] = true;
                q.emplace(x+1, y);
                if(x+1 == m-1)ans = false;
            }
            if(y-1 >= 0 && !grid[x][y-1] && !vis[x][y-1]){
                vis[x][y-1] = true;
                q.emplace(x, y-1);
                if(y-1 == 0)ans = false;
            }
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 1; i < m-1; i++) {
            for(int j = 1; j < n-1; j++) {
                if(!grid[i][j] && !vis[i][j]){
                    cnt += bfs(i, j, grid, vis, m, n);
                }
            }
        }
        return cnt;
    }
};