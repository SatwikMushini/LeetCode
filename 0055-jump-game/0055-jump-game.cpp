class Solution {
public:
    int dp[10001];
    bool find(int idx, vector<int>& nums){
        if(idx == nums.size()-1)return true;
        if(idx >= nums.size())return false;
        if(nums[idx] == 0)return false;
        if(dp[idx] != -1)return dp[idx];
        for(int i = 1; i <= nums[idx]; i++){
            if(find(idx+i, nums)){
               return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
    bool canJump(vector<int>& nums) {
        if(nums[0] == 0){
            return nums.size() == 1;
        }
        memset(dp, -1, sizeof(dp));
        return find(0, nums);
    }
};