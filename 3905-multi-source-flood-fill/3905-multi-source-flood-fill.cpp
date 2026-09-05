class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        sort(sources.begin(), sources.end(), [](vector<int>&a, vector<int>&b){
            return a[2] > b[2];
        });
        queue<pair<int,int>> q;
        for(auto x : sources){
            q.push({x[0], x[1]});
            grid[x[0]][x[1]] = x[2];
        }
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(auto [i,j] : dir){
                if(r+i >= 0 && r+i < n && c+j >= 0 && c+j < m && grid[r+i][c+j] == 0){
                    grid[r+i][c+j] = grid[r][c];
                    q.push({r+i, c+j});
                }
            }
        }
        return grid;
    }
};