class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        
        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)fresh++;
                else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        int minutes = 0;
        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                auto [x,y] = q.front(); q.pop();
                if(isValid(x-1,y,m,n) && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                    fresh--;
                }
                if(isValid(x,y+1,m,n) && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                    fresh--;
                }
                if(isValid(x+1,y,m,n) && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                    fresh--;
                }
                if(isValid(x,y-1,m,n) && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                    fresh--;
                }
            }
            if(!q.empty())minutes++;
        }
        return fresh > 0 ? -1 : minutes;
    }
};