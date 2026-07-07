class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        int concat = 0;
        while(n){
            ans += n % 10;
            if(n % 10)concat = concat * 10 + (n % 10);
            n /= 10;
        }
        int num = 0;
        while(concat){
            num = (num * 10) + concat % 10;
            concat /= 10;
        }
        return ans * num;
    }
};