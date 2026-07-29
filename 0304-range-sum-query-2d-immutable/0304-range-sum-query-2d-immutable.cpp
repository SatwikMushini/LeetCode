class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefix.resize(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                prefix[i+1][j+1] = matrix[i][j] + prefix[i+1][j];
            }
        }
        // for(int i = 0; i < m+1; i++){
        //     for(int j = 0; j < n+1; j++){
        //         cout << prefix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++){
            sum += prefix[i+1][col2+1] - prefix[i+1][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */