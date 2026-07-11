class Solution {
public:
    void find(int idx, int k, int target, vector<int>& store, vector<vector<int>>& ans){
        if(!k){
            if(!target)ans.push_back(store);
            return;
        }
        for(int i = idx; i <= 9; i++){
            store.push_back(i);
            find(i+1, k-1, target-i, store, ans);
            store.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>store;
        find(1, k, n, store, ans);
        return ans;
    }
};