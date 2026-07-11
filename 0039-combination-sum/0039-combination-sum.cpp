class Solution {
public:
    void find(vector<int>&arr, int idx, int target, vector<int>&store, vector<vector<int>>&ans){
        for(int i = idx; i < arr.size(); i++){
            store.push_back(arr[i]);
            if(target-arr[i] <= 0){
                if(target-arr[i] == 0){
                    ans.push_back(store);
                }
                store.pop_back();
                break;
            }
            find(arr, i, target-arr[i], store, ans);
            store.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cads, int target) {
        sort(cads.begin(), cads.end());
        vector<vector<int>> ans;
        vector<int>store;
        find(cads, 0, target, store, ans);
        return ans;
    }
};