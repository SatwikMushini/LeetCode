class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int ans = 0;
        for(auto x : s){
            if(x == '(')cnt++; else cnt--;
            if(cnt < 0){
                cnt = 0; ans++;
            }
        }
        return ans + cnt;
    }
};