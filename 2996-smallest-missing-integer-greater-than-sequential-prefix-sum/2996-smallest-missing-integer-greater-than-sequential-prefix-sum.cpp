class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int>seen(nums.begin(), nums.end());
        int currSum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]+1)currSum += nums[i];
            else break;
        }

        while(seen.count(currSum))currSum++;
        return currSum;
    }
};