class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>>ans(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int tot = 1, sum = img[i][j];
                if(i>0 && j>0 ){ sum+=img[i-1][j-1]; tot++;}
                if( i>0) { sum+=img[i-1][j];tot++;}
                if(i>0 && j+1 < n){ sum+=img[i-1][j+1];tot++;}
                if(j-1 >= 0 ){ sum+=img[i][j-1];tot++;}
                if(j+1 <n ){sum+=img[i][j+1];tot++;}
                if(i+1 < m && j-1>=0){sum+=img[i+1][j-1];tot++;}
                if(i+1 <m ){sum+=img[i+1][j];tot++;}
                if(i+1 <m && j+1 < n){sum+=img[i+1][j+1];tot++;}
                ans[i][j] = sum / tot;
            }
        }
        return ans;
    }
};