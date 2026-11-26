class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10)return false;
        for(int i = 10; i >= 0; i--) {
            if(n - i < 0)return (i & 1);
            n -= i;
        }
        return true;
    }
};