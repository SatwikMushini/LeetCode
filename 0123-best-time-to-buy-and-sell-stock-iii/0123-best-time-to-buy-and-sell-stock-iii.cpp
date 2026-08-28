class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        if(n == 1)return 0;

        vector<int>gp(n, 0);    // for getting right subarray max profit
        int maxi = prices[n-1];
        for(int i = n-1; i >= 0; i--){
            maxi = max(maxi, prices[i]);
            gp[i] = maxi - prices[i];
        }
        for(int i = n-2; i >= 0; i--){
            gp[i] = max(gp[i], gp[i+1]);
        }
        
        int mini = prices[0];
        int ans = gp[0];
        for(int i = 0; i < n-1; i++){  
            mini = min(mini, prices[i]);     
            ans = max(ans, prices[i] - mini + gp[i+1]); // for every left, gp[i+1] has right max profit
        }
        return ans;
    }
};