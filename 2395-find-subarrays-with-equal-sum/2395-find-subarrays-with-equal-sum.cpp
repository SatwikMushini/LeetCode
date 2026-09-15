class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>seen;
        for(int i = 1; i < nums.size(); i++){
            if(seen.count(nums[i] + nums[i-1]))return true;
            seen.insert(nums[i] + nums[i-1]);
        }
        return false;
    }
};