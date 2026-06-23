class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>NSE(n, n);
        stack<int>stk;
        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            NSE[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        int ans = 0, leftSmallerIdx = -1;
        stk = stack<int>();
        for(int i = 0; i < n; i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            leftSmallerIdx = stk.empty() ? -1 : stk.top();
            stk.push(i);

            ans = max(ans, heights[i] * (NSE[i] - leftSmallerIdx - 1));
        }
        return ans;
    }
};