class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                prefix[i+1][j+1] = prefix[i][j+1] + prefix[i+1][j] - prefix[i][j] +  mat[i][j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                int rlow = (i - k >= 0 ? i-k : 0) + 1;
                int clow = (j - k >= 0 ? j-k : 0) + 1;
                int rhigh = (i + k < m ? i+k : m-1) + 1;
                int chigh = (j + k < n ? j+k : n-1) + 1;

                mat[i][j] = prefix[rhigh][chigh] - prefix[rlow-1][chigh] - prefix[rhigh][clow-1] + prefix[rlow-1][clow-1];
            }
        }

        return mat;

    }
};