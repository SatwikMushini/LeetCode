class Solution {
public:
    int gcd(int a, int b){
        if(!a)return b;
        if(!b)return a;
        if(a > b)return gcd(a % b, b);
        return gcd(a, b % a);
    }
    int findGCD(vector<int>& nums) {
        int mini = 1e9, maxi = 0;
        for(auto x : nums){
            mini = min(x, mini);
            maxi = max(x, maxi);
        }
        return gcd(mini, maxi);
    }
};