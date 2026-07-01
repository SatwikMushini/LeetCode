class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, cnt = 0;
        unordered_map<int,int> seen;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == goal)cnt++;
            if(seen.count(sum - goal))cnt += seen[sum - goal];
            seen[sum]++;
        }
        return cnt;
    }
};