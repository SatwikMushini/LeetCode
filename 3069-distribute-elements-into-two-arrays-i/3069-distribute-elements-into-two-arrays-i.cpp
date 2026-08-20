class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>ans; ans.push_back(nums[0]);
        vector<int>temp; temp.push_back(nums[1]);

        for(int i = 2; i < nums.size(); i++){
            if(ans.back() > temp.back())ans.push_back(nums[i]);
            else temp.push_back(nums[i]);
        }

        for(auto x : temp){
            ans.push_back(x);
        }

        return ans;
    }
};