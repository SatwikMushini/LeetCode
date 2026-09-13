class Solution {
public:
    int give(int r, int c, auto& img1, auto& img2){
        int n = img1.size();
        int cnt = 0;
        for(int i = r; i < n; i++){
            for(int j = c; j < n; j++){
                if(img1[i][j] && img2[i-r][j-c])cnt++;
            }
        }
        return cnt;
    }
    int give2(int r, int c, auto& img1, auto& img2){
        int n = img1.size();
        int cnt = 0;
        for(int i = r; i < n; i++){
            for(int j = 0; j+c < n; j++){
                if(img1[i][j] && img2[i-r][j+c])cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxCnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                maxCnt = max(maxCnt, give(i, j, img1, img2));
                maxCnt = max(maxCnt, give(i, j, img2, img1));
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                maxCnt = max(maxCnt, give2(i, j, img1, img2));
                maxCnt = max(maxCnt, give2(i, j, img2, img1));
            }
        }
        return maxCnt;
    }
};