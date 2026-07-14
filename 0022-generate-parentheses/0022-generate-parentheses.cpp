class Solution {
public:
    void give(int n, string s, int openUnmatched, vector<string>& ans){
        if(n == 0 && openUnmatched == 0){
            ans.push_back(s);
            return;
        }
        if(n > 0)give(n-1, s+'(', openUnmatched, ans);
        if(openUnmatched > 0 && openUnmatched > n)give(n, s+')', openUnmatched-1, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        give(n, "", n, ans);
        return ans;
    }
};