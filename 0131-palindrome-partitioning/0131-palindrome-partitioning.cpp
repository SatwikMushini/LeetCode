class Solution {
public:
    bool check(string s){
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
    void give(int idx, string s, vector<string>& ds, vector<vector<string>>& ans){
        if(idx == s.size()){
            ans.push_back(ds);
            return;
        }
        string ss = "";
        for(int i = idx; i < s.size(); i++){
            ss += s[i];
            if(!check(ss))continue;
            ds.push_back(ss);
            give(i+1, s, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>ds;
        give(0, s, ds ,ans);
        return ans;
    }
};