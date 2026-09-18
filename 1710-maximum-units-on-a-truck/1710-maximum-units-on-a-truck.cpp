class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b){
            return a[1] > b[1];
        });
        int ans = 0;
        for(auto x : boxTypes){
            if(x[0] <= truckSize){
                truckSize -= x[0];
                ans += x[0] * x[1];
            }
            else{
                ans += truckSize * x[1];
                break;
            }
        }
        return ans;
    }
};