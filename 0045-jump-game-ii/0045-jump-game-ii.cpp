class Solution {
public:
    int giveMin(int idx, vector<int>& nums, vector<int>& dp){
        if(idx >= nums.size())return 1e9;
        if(idx == nums.size() - 1)return 0;
        if(dp[idx] != -1)return dp[idx];
        int mini = 1e5;
        for(int i = 1; i <= nums[idx]; i++){
            mini = min(mini, 1+giveMin(idx+i, nums, dp));
        }
        return dp[idx] = mini;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return giveMin(0, nums, dp);
    }
};