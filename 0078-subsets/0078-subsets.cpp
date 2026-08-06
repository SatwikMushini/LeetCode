class Solution {
public:
    void get(int idx, vector<int>& nums, vector<int>& ds, int n, vector<vector<int>>& ans){
        if(idx == n){
            ans.push_back(ds); return;
        }

        //pick
        ds.push_back(nums[idx]);
        get(idx+1, nums, ds, n, ans);
        ds.pop_back();

        // non pick
        get(idx+1, nums, ds, n, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        get(0, nums, ds, nums.size(), ans);
        return ans;
    }
};