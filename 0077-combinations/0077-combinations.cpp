class Solution {
public:
    void give(int idx, int n, int k, auto& ds, auto& ans){
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }
        for(int i = idx; i <= n; i++){
            ds.push_back(i);
            give(i+1, n, k, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>ds;
        give(1, n, k, ds, ans);
        return ans;
    }
};