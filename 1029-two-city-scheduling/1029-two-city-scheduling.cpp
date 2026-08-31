class Solution {
public:
    int dp[101][101][101];
    int give(int idx, auto &costs, int a, int b){
        if(idx == costs.size())return 0;
        if(dp[idx][a][b] != -1)return dp[idx][a][b];
        int n1 = 1e9, n2 = 1e9;
        if(a < costs.size() / 2)n1 = costs[idx][0] + give(idx+1, costs, a+1, b);
        if(b < costs.size() / 2)n2 = costs[idx][1] + give(idx+1, costs, a, b+1);
        return dp[idx][a][b] = min(n1, n2);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp, -1, sizeof(dp));
        return give(0, costs, 0, 0);
    }
};