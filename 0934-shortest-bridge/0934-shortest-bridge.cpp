class Solution {
public:
    bool isValid(int i, int j, int n){
        return (i >= 0 && i < n && j >= 0 && j < n);
    }
    void fill(int i, int j, vector<vector<int>>& grid, int n, vector<vector<bool>>& vis){
        if(!isValid(i,j,n) || grid[i][j] == 0 || vis[i][j])return;
        vis[i][j] = true;
        fill(i-1,j,grid,n,vis);
        fill(i,j+1,grid,n,vis);
        fill(i+1,j,grid,n,vis);
        fill(i,j-1,grid,n,vis);
    }
    bool BorderSharingWithZero(int i, int j, vector<vector<int>>& grid, int n){
        return ((isValid(i-1,j,n) && grid[i-1][j] == 0)
                || (isValid(i,j+1,n) && grid[i][j+1] == 0)
                || (isValid(i+1,j,n) && grid[i+1][j] == 0)
                || (isValid(i,j-1,n) && grid[i][j-1] == 0));
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            bool found = false;
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    fill(i,j,grid,n,vis);
                    found = true;
                    break;
                }
            }
            if(found)break;
        }
        queue<pair<int,int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] && BorderSharingWithZero(i,j,grid,n)){
                    q.emplace(i,j);
                }
            }
        }
        vector<int>dir = {-1,0,1,0,-1};
        int flips = 0;
        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                auto [x,y] = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    if(isValid(x+dir[i], y+dir[i+1], n) && !vis[x+dir[i]][y+dir[i+1]]){
                        if(grid[x+dir[i]][y+dir[i+1]] == 1)return flips;
                        q.emplace(x+dir[i], y+dir[i+1]);
                        vis[x+dir[i]][y+dir[i+1]] = true;
                    }
                }
            }
            if(!q.empty())flips++;
        }
        return -1;
    }
};