class Solution {
public:
    char invert(char c){
        if(c - 'A' > 25)return c - 32;
        else return c + 32;
    }
    void give(int idx, string s, int n, string valid, vector<string>& ans){
        if(idx == n){
            ans.push_back(valid);
            return;
        }
        give(idx+1, s, n, valid+s[idx], ans);
        if(s[idx] >= 'A')give(idx+1, s, n, valid+invert(s[idx]), ans);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        give(0, s, s.size(), "", ans);
        return ans;
    }
};