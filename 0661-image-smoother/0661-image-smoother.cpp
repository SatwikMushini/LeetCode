class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>>ans(m, vector<int>(n));
        vector<vector<int>>dirs = {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int neighbors = 1, sum = img[i][j];
                for(auto dir: dirs){
                    if(isValid(i+dir[0], j+dir[1], m, n)){
                        neighbors++;
                        sum += img[i+dir[0]][j+dir[1]];
                    }
                }
                ans[i][j] = sum / neighbors;
            }
        }
        return ans;
    }
};