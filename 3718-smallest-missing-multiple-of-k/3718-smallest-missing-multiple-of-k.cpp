class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int freq[101] = {0};
        for(auto x : nums)freq[x]++;
        for(int i = k; i <= 100; i+=k){
            if(!freq[i])return i;
        }
        return (100 / k + 1) * k;
    }
};