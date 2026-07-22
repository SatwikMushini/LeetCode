class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ils) {
        sort(ils.begin(), ils.end(), [](const vector<int>&a, const vector<int>& b){
            if(a[1] == b[1])return a[0] < b[0];
            return a[1] < b[1];
        });
        int end = ils[0][1], ans = 0;
        for(int i = 1; i < ils.size(); i++){
            if(ils[i][0] < end){
                ans++;
            }
            else end = ils[i][1];
        }
        return ans;
    }
};