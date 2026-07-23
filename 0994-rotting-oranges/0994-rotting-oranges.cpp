class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    grid[i][j] = 1;
                    q.push({i,j});
                }
            }
        }

        int level = -1;
        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                auto [x,y] = q.front(); q.pop();
                if(!isValid(x,y,m,n) || grid[x][y] == 0 || grid[x][y] == 2)continue;
                grid[x][y] = 2;
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x+1,y});
                q.push({x,y-1});
            }
            if(!q.empty())level++;
        }

        for(auto x : grid){
            for(auto y : x){
                if(y == 1)return -1;
            }
        }

        return level == -1 ? 0 : level;
    }
};