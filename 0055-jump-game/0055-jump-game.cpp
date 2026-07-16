class Solution {
public:
    unordered_map<int,bool>dp;
    bool find(int idx, vector<int>& nums){
        if(idx == nums.size()-1)return true;
        if(idx >= nums.size())return false;
        if(nums[idx] == 0)return false;
        if(dp.find(idx) != dp.end())return dp[idx];
        for(int i = 1; i <= nums[idx]; i++){
            if(find(idx+i, nums))return dp[idx+i] = true;
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        if(nums[0] == 0){
            return nums.size() == 1;
        }
        return find(0, nums);
    }
};