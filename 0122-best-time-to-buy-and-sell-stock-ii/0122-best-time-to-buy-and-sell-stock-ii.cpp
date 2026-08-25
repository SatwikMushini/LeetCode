class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int stock = prices[0];
        for(int i = 0; i < prices.size()-1; i++){
            if(prices[i] > prices[i+1]){
                profit += prices[i] - stock;
                stock = prices[i+1];
            }
        }

        profit += prices[prices.size()-1] - stock;
        return profit;

    }
};