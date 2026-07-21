class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            if(!isValid(x,y,m,n) || grid[x][y] == '0' || vis[x][y])continue;
            vis[x][y] = true;
            q.push({x-1, y});
            q.push({x, y+1});
            q.push({x+1, y});
            q.push({x, y-1});
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int islands = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    islands++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return islands;
    }
};