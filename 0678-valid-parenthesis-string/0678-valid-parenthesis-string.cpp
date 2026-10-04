class Solution {
public:
    bool give(int idx, int cnt, string& s, auto& dp) {
        if(idx == s.size()){
            return cnt == 0;
        }
        if(cnt < 0)return false;
        if(dp[idx][cnt] != -1)return dp[idx][cnt];

        bool n1, n2, n3;
        n1 = n2 = n3 = false;

        if(s[idx] == '(')n1 = give(idx+1, cnt+1, s, dp);
        else if(s[idx] == ')')n2 = give(idx+1, cnt-1, s, dp);
        else{
            bool n31 = give(idx+1, cnt+1, s, dp);
            bool n32 = give(idx+1, cnt-1, s, dp);
            bool n33 = give(idx+1, cnt, s, dp);
            if(n31 || n32 || n33)n3 = true;
        }

        return dp[idx][cnt] = (n1 || n2 || n3);
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));
        return give(0, 0, s, dp);
    }
};