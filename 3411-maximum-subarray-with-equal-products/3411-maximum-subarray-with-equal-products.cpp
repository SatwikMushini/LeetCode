class Solution {
public:
    int calcGCD(int a, int b) {
        if(!a)return b;
        if(!b)return a;
        if(a > b)return calcGCD(a % b, b);
        return calcGCD(a, b % a);
    }
    int maxLength(vector<int>& nums) {
        int ans = 1;
        for(int i = 0; i < nums.size()-1; i++) {
            int pro = nums[i], gcd = nums[i], lcm = nums[i];
            for(int j = i+1; j < nums.size(); j++) {
                pro *= nums[j];
                gcd = calcGCD(gcd, nums[j]);
                lcm = (lcm / calcGCD(lcm, nums[j])) * nums[j];
                if(pro >= 2520 * gcd * lcm)break;
                if(lcm * gcd == pro)ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};