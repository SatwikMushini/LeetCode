
bool calculated = false;
vector<bool>ans;

class Solution {
public:
    bool winnerSquareGame(int n) {
        if(!calculated){
            calculated = true;
            ans.assign(1e5+1, false);

            ans[1] = ans[3] = ans[4] = true; 
            ans[2] = false;

            for(int i = 5; i <= 1e5; i++){
                int possi = sqrt(i);
                if(possi * possi == i){
                    ans[i] = true;
                    continue;
                }
                bool found = false;
                for(int j = 1; j <= possi; j++){
                    if(ans[i - j * j] == false){
                        found = true; break;
                    }
                }
                ans[i] = found ? true : false;
            }
        }
        return ans[n];
    }
};