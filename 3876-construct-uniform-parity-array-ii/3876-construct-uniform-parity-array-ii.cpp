class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        if(mini & 1)return true;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & 1)return false;
        }
        return true;
    }
};