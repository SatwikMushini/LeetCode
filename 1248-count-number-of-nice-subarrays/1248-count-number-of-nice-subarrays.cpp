class Solution {
public:
    int findSubarrays(vector<int>& nums, int k){
        if(k < 0)return 0;
        int sum = 0, left = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += (nums[i] & 1);
            while(sum > k){
                sum -= (nums[left] & 1); left++;
            }
            cnt += i - left + 1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return findSubarrays(nums, k) - findSubarrays(nums, k-1);
    }
};