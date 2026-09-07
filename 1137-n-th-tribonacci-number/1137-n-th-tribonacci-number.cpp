int dp[38];
bool calc = false;
class Solution {
public:
    int trib(int n){
        if(n == 0)return 0;
        if(n == 1 || n == 2)return 1;
        if(dp[n] != -1)return dp[n];
        return dp[n] = trib(n-1)+trib(n-2)+trib(n-3);
    }
    int tribonacci(int n) {
        if(!calc){
            calc = true; 
            memset(dp, -1, sizeof(dp));
            dp[0] = 0, dp[1] = dp[2] = 1;
            trib(37);
        }
        return dp[n];
    }
};