class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        while(sum > 9){
            res += '9';
            sum -= 9;
        }
        res += to_string(sum);
        int n = res.size();
        if(res.size() > num)return "";
        while(n < num){
            res += '0';
            n++;
        }
        return res;
    }
};