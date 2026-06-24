class StockSpanner {
public:
    StockSpanner() {
        
    }
    int cnt = 1;
    stack<pair<int,int>>prices;
    int next(int price) {
        while(!prices.empty() && prices.top().first <= price){
            prices.pop();
        }
        int res = prices.empty() ? cnt : cnt - prices.top().second;
        prices.push({price, cnt}); cnt++;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */