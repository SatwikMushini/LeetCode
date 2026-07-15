class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>cnt(3, 0);
        for(auto x : bills){
            if(x == 5)cnt[0]++;
            else if(x == 10){
                if(cnt[0] == 0)return false;
                cnt[0]--;
                cnt[1]++;
            }
            else{
                if(cnt[1] >= 1 && cnt[0] >= 1){
                    cnt[1]--; cnt[0]--;
                }
                else if(cnt[0] >= 3){
                    cnt[0] -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};