class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size-1;

        vector<int> res(size);
        int k = size - 1;
        while(left != right){
            if(abs(nums[left]) < abs(nums[right])){
                res[k--] = nums[right] * nums[right];
                right--;
            }
            else{
                res[k--] = nums[left] * nums[left];
                left++;
            }
        }
        res[k] = nums[left] * nums[left];
        return res;
    }
};