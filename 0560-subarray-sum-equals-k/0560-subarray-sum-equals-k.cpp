class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSubarraySum;
        int prefixSum = 0;
        int cnt = 0;
        
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            if(prefixSum == k)cnt++;
            if(prefixSubarraySum.count(prefixSum - k)){
                cnt += prefixSubarraySum[prefixSum - k];
            }
            prefixSubarraySum[prefixSum]++;
        }

        return cnt;
    }
};