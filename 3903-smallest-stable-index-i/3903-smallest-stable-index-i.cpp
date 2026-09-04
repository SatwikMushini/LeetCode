class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = nums[0];
        vector<int>mini(nums.size()); mini[nums.size()-1] = nums[nums.size()-1];

        for(int i = nums.size()-2; i >= 0; i--){
            mini[i] = min(mini[i+1], nums[i]);
        }

        for(int i = 0; i < nums.size(); i++){
            maxi = max(maxi, nums[i]);
            if(maxi - mini[i] <= k)return i;
        }

        return -1;
    }
};