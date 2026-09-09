class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(last < i)return false;
            last = max(last, i + nums[i]);
        }
        return true;
    }
};