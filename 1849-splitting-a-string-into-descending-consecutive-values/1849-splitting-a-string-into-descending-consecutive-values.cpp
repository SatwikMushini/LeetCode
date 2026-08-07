class Solution {
public:
    bool give(long long num, int idx, string s){
        // if(idx >= s.size())return false;

        string currNum = "";
        for(int i = idx; i < s.size(); i++){
            currNum += s[i];
            long long toNum = stoll(currNum);

            if(toNum >= num || toNum > 1e10)break;

            if(num == 1e18 || toNum + 1 == num){
                if(give(toNum, i+1, s))return true;
            }
            if(i == s.size()-1){
                if(toNum + 1 == num)return true;
                else return false;
            }
        }
        return false;
    }
    bool splitString(string s) {
        return give(1e18, 0, s);
    }
};