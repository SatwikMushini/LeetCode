class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        unordered_map<int,int>freq;
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            while(freq[nums[i]] > k){
                freq[nums[left]]--;
                if(!freq[nums[left]])freq.erase(nums[left]);
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};