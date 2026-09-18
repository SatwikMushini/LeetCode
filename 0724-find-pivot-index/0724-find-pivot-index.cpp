class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        vector<int> sums(size);
        sums[0] = nums[0];
        for(int i = 1; i < size; i++){
            sums[i] = sums[i-1]+nums[i];
        }
        if(!(sums[size-1] - sums[0]))return 0;
        for(int i = 1; i < size-1; i++){
            int right_sum = sums[size-1] - sums[i];
            if(sums[i-1] == right_sum)return i;
        }
        if(!sums[size-2])return size-1;
        return -1;
    }
};