class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ans = 0;
        int i = cost.size()-1;
        for(; i >= 2; i -= 3){
            ans += cost[i] + cost[i-1];
        }
        for(; i >= 0; i--){
            ans += cost[i];
        }
        return ans;
    }
};