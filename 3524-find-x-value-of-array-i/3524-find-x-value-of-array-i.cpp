class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0ll);

        vector<long long>prev(k, 0ll);
        for(int i = 0; i < nums.size(); i++){

            vector<long long>curr(k, 0ll);
            int rem = nums[i] % k;
            curr[rem]++;

            for(int oldRem = 0; oldRem < k; oldRem++){
                int newRem = (oldRem * (nums[i] % k)) % k;
                curr[newRem] += prev[oldRem];
            }

            for(int j = 0; j < k; j++){
                res[j] += 1ll*curr[j];
            }

            prev = move(curr);
        }
        return res;
    }
};