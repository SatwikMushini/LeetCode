class Solution {
public:
    string removeKdigits(string num, int k) {
        if(!k)return num;
        if(k >= num.size())return "0";
        string ans = "";
        for(int i = 0; i < num.size(); i++){
            while(ans != "" && ans.back() > num[i]){
                ans.pop_back(); k--;
                if(!k)break;
            }
            if(!k){
                ans += num.substr(i, num.size() - i);
                break;
            }
            ans += num[i];
        }
        int i = 0;
        for(; i < ans.size(); i++){
            if(ans[i] != '0')break;
        }
        ans = ans.substr(i, ans.size()-i);
        while(ans!= "" && k--){
            ans.pop_back();
        }
        if(ans == "")return "0";
        return ans;
    }
};