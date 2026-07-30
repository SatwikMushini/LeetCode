class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0, step = 1;
        while(n >= 8){
            ans += 8 * step;
            step++;
            n -= 8;
        }
        ans += step * n;
        return ans;
    }
};