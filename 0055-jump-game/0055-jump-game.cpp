class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return true;
        if(nums[0] == 0)return false;
        vector<bool>reachEnd(n, false);
        reachEnd[n-1] = true;
        for(int i = n-2; i >= 0; i--){
            if(i + nums[i] >= n-1){
                reachEnd[i] = true;
            }
            else{
                for(int j = i+1; j <= i+nums[i]; j++){
                    if(reachEnd[j]){
                        reachEnd[i] = true;
                        break;
                    }
                }
            }
        }
        return reachEnd[0];
    }
};