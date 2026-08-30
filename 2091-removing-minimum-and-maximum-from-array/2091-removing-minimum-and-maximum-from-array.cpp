class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0, maxIdx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[maxIdx])maxIdx = i;
            if(nums[i] < nums[minIdx])minIdx = i;
        }
        if(minIdx > maxIdx)swap(minIdx, maxIdx);
        int d1 = minIdx + 1 + (n - maxIdx);
        int d2 = maxIdx + 1, d3 = n - minIdx;
        return min(d1, min(d2, d3));
    }
};