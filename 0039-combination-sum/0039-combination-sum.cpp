class Solution {
public:
    void findSum(vector<int>&arr, int idx, int sum, vector<int>&store, vector<vector<int>>& ans){
        if(sum <= 0){
            if(sum == 0){
                ans.push_back(store);
            }
            return;
        }
        if(idx == arr.size())return;
        store.push_back(arr[idx]);
        findSum(arr, idx, sum-arr[idx], store, ans);
        store.pop_back();
        findSum(arr, idx+1, sum, store, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>store;
        findSum(candidates, 0, target, store, ans);
        return ans;
    }
};