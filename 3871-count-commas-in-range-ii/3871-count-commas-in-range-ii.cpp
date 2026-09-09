class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1e3)return 0;
        if(n < 1e6)return n - 999;

        long long n0 = 1e6 - 1e3;
        long long n1 = (1e9 - 1e6) * 2;
        long long n2 = (1e12 - 1e9) * 3;
        long long n3 = (1e15 - 1e12) * 4;

        if(n < 1e9)return n0 + 1ll * (n - 1e6 + 1) * 2;
        if(n < 1e12)return n0 + n1 + 1ll * (n - 1e9 + 1) * 3;
        if(n < 1e15)return n0 + n1 + n2 + 1ll * (n - 1e12 + 1) * 4;

        return n0 + n1 + n2 + n3 + 5;

    }
};