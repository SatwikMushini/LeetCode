class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0, right = 0;
        int zerocnt = 0;
        for(; right < size; right++){
            if(!k)break;
            if(nums[right] == 0)zerocnt++;
            if(zerocnt == k){
                right++;
                break;
            }
        }
        if(right >= size)return size;
        int res = right;
        for(; right < size; right++){
            if(nums[right] == 0){
                res = max(res, right - left);
                while(nums[left] != 0){
                    left++;
                }
                left++;
            }
        }
        res = max(res, right - left);
        return res;
    }
};