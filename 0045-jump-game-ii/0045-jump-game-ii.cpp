class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1e9);
        dp[n-1] = 0;

        for(int i = n-2; i >= 0; i--){
            int mini = 1e9;
            for(int j = i+1; j < n; j++){
                if(j > i + nums[i])break;
                mini = min(mini, dp[j]);
            }
            dp[i] = mini + 1;
        }
        return dp[0];

    }
};