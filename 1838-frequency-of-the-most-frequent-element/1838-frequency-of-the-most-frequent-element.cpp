class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int left = 0;
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += 1ll*nums[i];
            long long reqSum = 1ll * nums[i] * (i - left + 1);
            while(reqSum - sum > k){
                sum -= nums[left];
                reqSum -= nums[i];
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};