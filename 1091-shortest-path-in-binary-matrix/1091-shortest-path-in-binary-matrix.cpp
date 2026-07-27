class Solution {
public:
    bool isValid(int i, int j, int n){
        return (i >= 0 && i < n && j >= 0 && j < n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1])return -1;

        vector<vector<bool>>vis(n, vector<bool>(n, false));
        vector<pair<int,int>>dir = {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
        queue<pair<int,int>>q;
        vis[0][0] = true;
        q.emplace(0,0);
        int level = 1;
        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                auto [x,y] = q.front(); q.pop();
                if(x == n-1 && y == n-1)return level;
                for(auto &[i,j]: dir){
                    if(isValid(x+i,y+j,n) && grid[x+i][y+j] == 0 && !vis[x+i][y+j]){
                        vis[x+i][y+j] = true;
                        q.emplace(x+i, y+j);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};