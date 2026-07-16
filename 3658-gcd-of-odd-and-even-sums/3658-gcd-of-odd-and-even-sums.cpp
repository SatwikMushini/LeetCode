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
    //https://teams.microsoft.com/dl/launcher/launcher.html?url=%2F_%23%2Fmeet%2F479242181793111%3Fp%3DEqvfYr0mDko46tVlwZ%26anon%3Dtrue&type=meet&deeplinkId=8ed69948-87f2-4c9c-bc22-d7728c4a54a3&directDl=true&msLaunch=true&enableMobilePage=true&suppressPrompt=true
};