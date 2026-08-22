class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0, pro = 1;
        while(n){
            sum += n % 10;
            pro *= n % 10;
            n /= 10;
        }
        sum += pro;
        if(temp % sum == 0)return true;
        else return false;
    }
};