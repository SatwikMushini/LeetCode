class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& ils) {
        sort(ils.begin(), ils.end(), [](const vector<int>&a, const vector<int>&b){
            if(a[0] == b[0])return a[1] > b[1];
            return a[0] < b[0];
        });
        int j = 0, cnt = 1;
        for(int i = 1; i < ils.size(); i++){
            if(ils[i][0] >= ils[j][0] && ils[i][1] <= ils[j][1])continue;
            else{
                cnt++;
                j = i;
            }
        }
        return cnt;
    }
};