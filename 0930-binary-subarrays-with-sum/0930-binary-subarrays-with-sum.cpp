class Solution {
public:
    int findSubarrays(vector<int>& nums, int goal){
        int left = 0, cnt = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum > goal){
                sum -= nums[left++];
            }
            cnt += i - left + 1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt1 = findSubarrays(nums, goal);
        int cnt2 = goal-1 >= 0 ? findSubarrays(nums, goal-1) : 0;
        return cnt1 - cnt2;
    }
};