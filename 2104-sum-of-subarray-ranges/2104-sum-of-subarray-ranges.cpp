class Solution {
public:
    long long subArrayMax(vector<int>&nums){
        int n = nums.size();
        stack<int>stk;
        vector<int> rightGreater(n, n);
        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && nums[stk.top()] < nums[i]){
                stk.pop();
            }
            rightGreater[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        int leftGreater = -1; stk = stack<int>();
        long long sum = 0;
        for(int i = 0; i < n; i++){
            while(!stk.empty() && nums[stk.top()] <= nums[i]){
                stk.pop();
            }
            leftGreater = stk.empty() ? -1 : stk.top();
            sum += 1ll * nums[i] * (i - leftGreater) * (rightGreater[i] - i);
            stk.push(i);
        }
        return sum;
    }
    long long subArrayMin(vector<int>&nums){
        int n = nums.size();
        stack<int>stk;
        vector<int> rightSmaller(n, n);
        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && nums[stk.top()] > nums[i]){
                stk.pop();
            }
            rightSmaller[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        int leftSmaller = -1; stk = stack<int>();
        long long sum = 0;
        for(int i = 0; i < n; i++){
            while(!stk.empty() && nums[stk.top()] >= nums[i]){
                stk.pop();
            }
            leftSmaller = stk.empty() ? -1 : stk.top();
            sum += 1ll * nums[i] * (i - leftSmaller) * (rightSmaller[i] - i);
            stk.push(i);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subArrayMax(nums) -subArrayMin(nums);
    }
};