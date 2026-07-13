class Solution {
public:
    void run(vector<int>& arr, int i, vector<vector<int>>& nums){
        nums.push_back(arr);
        if(i == arr.size() - 1)return;
        
        for(int k = i; k < arr.size()-1; k++){
            for(int j = k+1; j < arr.size(); j++){
                swap(arr[k], arr[j]);
                run(arr, k+1, nums);
                swap(arr[k], arr[j]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        run(nums, 0, ans);
        return ans;
    }
};