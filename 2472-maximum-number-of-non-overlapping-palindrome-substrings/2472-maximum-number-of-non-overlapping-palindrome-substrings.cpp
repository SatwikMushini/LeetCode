class Solution {
public:
    int dp[2001];
    bool isPali(string& s, int a, int b){
        while(a <= b){
            if(s[a] != s[b])return false;
            a++; b--;
        }
        return true;
    }
    int give(int idx, string& s, int k){
        if(idx == s.size())return 0;
        if(dp[idx] != -1)return dp[idx];

        int maxi = give(idx+1, s, k);
        for(int i = idx + k - 1; i < s.size(); i++){
            if(isPali(s, idx, i)){
                maxi = max(maxi, 1+give(i+1, s, k));
            }
        }
        
        return dp[idx] = maxi;
    }
    int maxPalindromes(string s, int k) {
        if(k == 1)return s.size();
        memset(dp, -1, sizeof(dp));
        return give(0, s, k);
    }
};