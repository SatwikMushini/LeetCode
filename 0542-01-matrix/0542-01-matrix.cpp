class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dis(m, vector<int>(n,-1));

        queue<pair<int,int>>q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.emplace(i,j);
                    dis[i][j] = 0;
                }
            }
        }
    
        if(q.empty() || q.size() == m*n)return mat;

        vector<pair<int,int>>dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();

            for(auto &[i,j]: dir){
                if(isValid(x+i,y+j,m,n) && dis[x+i][y+j] == -1){
                    dis[x+i][y+j] = dis[x][y]+1;
                    q.emplace(x+i,y+j);
                }
            }
        }

        return dis;

    }
};