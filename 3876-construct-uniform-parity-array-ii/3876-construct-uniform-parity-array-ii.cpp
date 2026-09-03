class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] & 1)return true;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] & 1)return false;
        }
        return true;
    }
};