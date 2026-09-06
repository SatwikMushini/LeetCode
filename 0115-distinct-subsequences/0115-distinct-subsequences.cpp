class Solution {
public:
    int dp[1000][1000];
    int give(int idx, string curr, string& s, string& t){
        int pos = curr.size();
        if(pos == t.size())return 1;
        if(idx >= s.size())return 0;

        if(dp[idx][pos] != -1)return dp[idx][pos];

        int cnt = 0;
        for(int i = idx; i < s.size(); i++){
            if(s[i] == t[pos])cnt += give(i+1, curr+t[pos], s, t);
        }
        return dp[idx][pos] = cnt;
    }
    int numDistinct(string s, string t) {
        if(s.size() < t.size())return 0;
        memset(dp, -1, sizeof(dp));
        return give(0, "", s, t);
    }
};