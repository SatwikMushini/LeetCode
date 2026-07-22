class Solution {
public:
    bool isValid(int i, int j, int n){
        return (i >= 0 && i < n && j >= 0 && j < n);
    }
    int maxDistance(vector<vector<int>>& grid) {
        int maxDis = -1;
        int n = grid.size();
        vector<vector<int>>dis(n, vector<int>(n, -1));
        queue<pair<int,int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        if(q.empty() || q.size() == n*n)return -1;
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            if(isValid(x-1,y,n) && dis[x-1][y] == -1){
                dis[x-1][y] = dis[x][y] + 1;
                q.push({x-1, y});
            }
            if(isValid(x,y+1,n) && dis[x][y+1] == -1){
                dis[x][y+1] = dis[x][y] + 1;
                q.push({x, y+1});
            }
            if(isValid(x+1,y,n) && dis[x+1][y] == -1){
                dis[x+1][y] = dis[x][y] + 1;
                q.push({x+1, y});
            }
            if(isValid(x,y-1,n) && dis[x][y-1] == -1){
                dis[x][y-1] = dis[x][y] + 1;
                q.push({x, y-1});
            }
        }
        for(auto x : dis){
            for(auto y : x)maxDis = max(maxDis, y);
        }
        return maxDis;
    }
};