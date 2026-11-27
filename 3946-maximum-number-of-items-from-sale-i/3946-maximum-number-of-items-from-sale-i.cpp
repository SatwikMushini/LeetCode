class Solution {
public:
    int dp[1001][1501];
    int solve(int idx, int budget, auto& items, auto& copies, int min_cost) {

        if(idx >= items.size()) return budget / min_cost;   //play's imp role
        if(dp[idx][budget] != -1)return dp[idx][budget];

        int price = items[idx][1];

        int ans = solve(idx+1, budget, items, copies, min_cost); 
        if(budget >= price)ans = max(ans, 1 + copies[idx] + solve(idx+1, budget-price, items, copies, min_cost));

        return dp[idx][budget] = ans;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        vector<int>copies(n, 0);

        int min_cost = 1e9;
        for(int i = 0; i < n; i++) {
            min_cost = min(min_cost, items[i][1]);
            for(int j = 0; j < n; j++) {
                if(i == j)continue;
                if(items[j][0] % items[i][0] == 0)copies[i]++;
            }
        }

        memset(dp, -1, sizeof(dp));
        return solve(0, budget, items, copies, min_cost);
    }
};