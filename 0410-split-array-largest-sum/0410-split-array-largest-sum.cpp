class Solution {
public:
    bool check(int subSum, vector<int>&nums, int k){
        int sum = 0, subcnt = 1;
        for(auto x : nums){
            if(sum + x <= subSum)sum += x;
            else{
                subcnt++;
                sum = x;
            }
        }
        return subcnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()), high = 1e9;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(check(mid, nums, k)){
                high = mid;
            }
            else low = mid+1;
        }
        return high;
    }
};