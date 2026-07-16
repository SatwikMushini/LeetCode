class Solution {
public:
    int gcd(int a, int b){
        if(!a || !b)return (a ? a : b);
        if(a > b)return gcd(a % b, b);
        else return gcd(a, b % a);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        int maxi = nums[0];
        for(int i = 0; i < n; i++){
            maxi = max(nums[i], maxi);
            prefix[i] = gcd(nums[i], maxi);
        }
        sort(prefix.begin(), prefix.end());
        long long sum = 0;
        for(int i = 0 ; i < n/2; i++){
            sum += gcd(prefix[i], prefix[n-i-1]);
        }
        return sum;
    }
};