class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() <= 2)return nums.size();
        int maxele = *max_element(nums.begin(), nums.end());
        int totalBits = 0;
        while(maxele){
            totalBits++;
            maxele >>= 1;
        }
        return (1 << totalBits);
    }
};