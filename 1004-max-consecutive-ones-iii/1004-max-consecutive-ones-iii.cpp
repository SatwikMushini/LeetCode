class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(!nums[i]){
                if(k){
                    k--;
                }
                else{
                    while(nums[left])left++;
                    left++;
                }
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};