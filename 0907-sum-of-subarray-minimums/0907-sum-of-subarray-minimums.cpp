class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> rightSmaller(n, -1);
        stack<int>stk;
        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                stk.pop();
            }
            rightSmaller[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        int leftSmaller = -1;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                stk.pop();
            }
            leftSmaller = stk.empty() ? -1 : stk.top();
            stk.push(i);
            sum = (sum + 1ll * arr[i] * (i - leftSmaller) * (rightSmaller[i] - i)) % 1000000007;
        }
        return (int)sum;
    }
};