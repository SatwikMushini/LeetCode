class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>seen;
        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i < k; i++){
            seen[nums[i]]++;
            sum += 1ll*nums[i];
        }

        long long maxi = 0;
        if(seen.size() == k)maxi = sum;

        int j = 0;
        for(int i = k; i < n; i++){
            sum += nums[i];
            sum -= nums[j];

            seen[nums[j]]--;
            if(!seen[nums[j]])seen.erase(nums[j]);
            seen[nums[i]]++;

            if(seen.size() == k)maxi = max(maxi, sum);
            j++;
        }
        return maxi;
    }
};