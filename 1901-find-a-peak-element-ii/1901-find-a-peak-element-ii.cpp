class Solution {
public:
    int findMaxRowIdx(int col, vector<vector<int>>& mat){
        int maxi = -1, maxRow = -1;
        for(int i = 0; i < mat.size(); i++){
            if(maxi < mat[i][col]){
                maxi = mat[i][col];
                maxRow = i;
            }
        }
        return maxRow;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int low = 0, high = cols-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int maxRowIdx = findMaxRowIdx(mid, mat);
            int left = (mid-1 < 0 ? -1 : mat[maxRowIdx][mid-1]), right = (mid+1 < cols ? mat[maxRowIdx][mid+1] : -1);
            if(mat[maxRowIdx][mid] > left && mat[maxRowIdx][mid] > right)return {maxRowIdx, mid};
            if(mat[maxRowIdx][mid] < left)high = mid-1;
            else low = mid+1;
        }
        return {-1,-1};
    }
};