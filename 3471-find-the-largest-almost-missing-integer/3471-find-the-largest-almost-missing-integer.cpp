class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == 1){
            unordered_map<int,int>freq;
            for(auto x : nums)freq[x]++;
            int ans = -1;
            for(auto &[key, value]: freq){
                if(value == 1)ans = max(ans, key);
            }
            return ans;
        }
        if(k == nums.size()){
            return *max_element(nums.begin(), nums.end());
        }
        //front check
        bool front = true, back = true;
        for(int i = 1; i < nums.size(); i++){
            if(nums[0] == nums[i]){
                front = false; break;
            }
        }
        //back check
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[nums.size()-1] == nums[i]){
                back = false; break;
            }
        }
        if(front && back)return max(nums[0], nums[nums.size()-1]);
        if(front || back){
            if(front)return nums[0];
            return nums[nums.size()-1];
        }
        return -1;
    }
};