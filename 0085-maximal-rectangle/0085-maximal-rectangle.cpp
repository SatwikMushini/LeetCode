class Solution {
public:
    int solve(vector<int>& heights){
        stack<int>stk;
        int maxRectangleArea = 0;
        for(int i = 0; i < heights.size(); i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int idx = stk.top(); stk.pop();
                int leftSmallerIdx = stk.empty() ? -1 : stk.top();
                maxRectangleArea = max(maxRectangleArea, heights[idx] * (i - leftSmallerIdx - 1));
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int idx = stk.top(); stk.pop();
            int leftSmallerIdx = stk.empty() ? -1 : stk.top();
            int rightSmallerIdx = heights.size();
            maxRectangleArea = max(maxRectangleArea, heights[idx] * (rightSmallerIdx - leftSmallerIdx - 1));
        }
        return maxRectangleArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1')heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans, solve(heights));
        }
        return ans;
    }
};