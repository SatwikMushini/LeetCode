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
        q.emplace(0,0);

        int level = 1;

        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                auto [x,y] = q.front(); q.pop();
                if(!isValid(x,y,n) || grid[x][y] == 1 || vis[x][y]){
                    continue;
                }
                if(x == n-1 && y == n-1)return level;
                vis[x][y] = true;
                for(auto &[i,j]: dir){
                    q.emplace(x+i, y+j);
                }
            }
            level++;
        }
        return -1;
    }
};