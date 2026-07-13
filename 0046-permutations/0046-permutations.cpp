class Solution {
public:
    void findPermutations(vector<int>&nums, vector<int>&store, vector<int>&visited, vector<vector<int>>& ans){
        if(store.size() == nums.size()){
            ans.push_back(store);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited[nums[i] + 10])continue;

            visited[nums[i] + 10] = 1;
            store.push_back(nums[i]);

            findPermutations(nums, store, visited, ans);

            visited[nums[i] + 10] = 0;
            store.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>visited(21, 0);
        vector<int>store;
        findPermutations(nums, store, visited, ans);
        return ans;
    }
};