class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> keyPads = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.size();
        int i = 0;
        string res = "";
        vector<string>ans;
        for(auto x : keyPads[digits[i] - '0']){
            res += x;
            if(i+1 < n)
            for(auto y : keyPads[digits[i+1] - '0']){
                res += y;
                if(i+2 < n){
                    for(auto z : keyPads[digits[i+2] - '0']){
                        res += z;
                        if(i+3 < n){
                            for(auto w : keyPads[digits[i+3] - '0']){
                                res += w;
                                ans.push_back(res);
                                res.pop_back();
                            }
                        }
                        else ans.push_back(res);
                        res.pop_back();
                    }
                }
                else ans.push_back(res);
                res.pop_back();
            }
            else ans.push_back(res);
            res.pop_back();
        }
        return ans;
    }
};