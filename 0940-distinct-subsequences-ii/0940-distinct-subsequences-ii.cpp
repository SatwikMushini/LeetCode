class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9+7;
        vector<int>pos(255, -1);

        vector<int>dp(s.size()+1, 0);
        dp[0] = 0; dp[1] = 1;
        pos[s[0]] = 0;
        
        for(int i = 1; i < s.size(); i++){
            dp[i+1] = (1ll * dp[i] * 2 + ((pos[s[i]] != -1) ? -dp[pos[s[i]]] : 1) + mod) % mod;
            pos[s[i]] = i;
        }

        return dp[s.size()];
    }
};