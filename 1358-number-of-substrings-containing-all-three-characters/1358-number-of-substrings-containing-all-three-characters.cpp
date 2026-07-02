class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1, b = -1, c = -1;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a')a = i;
            else if(s[i] == 'b')b = i;
            else c = i;
            if(a >= 0 && b >= 0 && c >= 0){
                int mini = min(a, min(b, c));
                cnt += mini + 1;
            }
        }
        return cnt;
    }
};