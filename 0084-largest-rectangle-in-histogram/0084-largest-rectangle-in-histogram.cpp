class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        stack<int>stk;
        for(int i = 0; i < n; i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int idx = stk.top(); stk.pop();
                int leftSmallerIdx = stk.empty() ? -1 : stk.top();
                ans = max(ans, heights[idx] * (i - leftSmallerIdx - 1));
                cout << ans << " ";
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int idx = stk.top(); stk.pop();
            int leftSmallerIdx = stk.empty() ? -1 : stk.top();
            ans = max(ans, heights[idx] * (n - leftSmallerIdx - 1));
            cout << ans << " ";
        }
        return ans;
    }
};