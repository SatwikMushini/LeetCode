class Solution {
public:
    bool valid(string s){
        if(s.empty())return false;
        if(s.size() > 1 && s[0] == '0')return false;
        return stoi(s) <= 255;
    }
    void give(string res, string store, int idx, int dots, string &s, vector<string>& ans){
        if(dots == 0){
            if(valid(s.substr(idx)))ans.push_back(res + s.substr(idx));
            return;
        }
        for(int i = idx; i < s.size(); i++){
            store += s[i];
            if(valid(store)){
                give(res + store + '.', "", i+1, dots-1, s, ans);
            }
            else if(store.size() >= 3)break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() >  12)return {};
        vector<string>ans;
        give("", "", 0, 3, s, ans);
        return ans;
    }
};