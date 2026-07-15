class Solution {
public:
    int gcd(int a, int b){
        if(!b)return a; if(!a)return b;
        if(a > b)return gcd(a % b, b);
        return gcd(a, b % a);
    }
    int gcdOfOddEvenSums(int n) {
        return gcd(n*n, n*(n+1));
    }
};