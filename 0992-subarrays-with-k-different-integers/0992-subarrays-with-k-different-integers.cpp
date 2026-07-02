class Solution {
public:
    int cntAtMost(vector<int>& nums, int k){
        if(k < 0)return 0;
        int left = 0, cnt = 0;
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(!mpp[nums[left]])mpp.erase(nums[left]);
                left++;
            }
            cnt += i - left + 1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return cntAtMost(nums, k) - cntAtMost(nums, k-1);
    }
};