class Solution {
public:
    bool check(auto &nums){
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i)return false;
        }
        return true;
    }
    int solve(auto &nums) {
        int pos = min_element(nums.begin(), nums.end()) - nums.begin();
        vector<int>store;
        for(int i = 0; i < pos; i++) {
            store.push_back(nums[i]);
        }
        for(int i = pos; i < nums.size(); i++) {
            nums[i-pos] = nums[i];
        }
        int k = 0;
        for(int i = nums.size()-store.size(); i < nums.size(); i++) {
            nums[i] = store[k++];
        }
        if(check(nums))return k;
        int ele = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            nums[i-1] = nums[i];
        }
        nums[nums.size()-1] = ele;
        reverse(nums.begin(), nums.end());
        if(check(nums))return k+2;
        return 1e9;
    }
    int minOperations(vector<int>& nums) {
        vector<int>revNums = nums;
        reverse(revNums.begin(), revNums.end());
        int c1 = solve(nums);
        int c2 = 1 + solve(revNums);
        int ans = min(c1,c2);
        return (ans == 1e9 ? -1 : ans);
    }
};