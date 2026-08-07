class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1; 
        while(low <= high){         //O(log(n))
            int mid = (low + high) >> 1;
            if(nums[mid] > target){
                high = mid-1;
            }
            else low = mid+1;
        }
        if(high == -1 || nums[high] != target)return {-1,-1};

        int h = high;
        low = 0; high = nums.size()-1;

        while(low <= high){         //O(log(n))
            int mid = (low + high) >> 1;
            if(nums[mid] >= target){
                high = mid-1;
            }
            else low = mid+1;
        }
        
        return {low, h};
    }
};