class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        long long res = 0;
        for(int i = n/2; i < n; i++){
            res += 0ll + nums[i];
        }
        for(int i = 0; i < n/2; i++){
            res -= 0ll + nums[i];
        }
        return res;
    }
};