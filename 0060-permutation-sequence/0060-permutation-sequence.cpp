class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int>factorials(n+1, 1);
        for(int i = 1; i <= n; i++){
            factorials[i] = factorials[i-1] * i; 
        }

        int st = 1, end = factorials[n];
        int partLen = end / n;

        vector<int>remains(n+1);
        for(int i = 1; i <= n; i++)remains[i] = i;

        string res = "";
        while(n > 1){
            int partBelong = (k - st) / partLen + 1;
            res += remains[partBelong] + '0'; remains.erase(remains.begin()+partBelong);
            st += (partLen * (partBelong-1)); 
            end = st + partLen - 1;
            partLen = factorials[n-2];
            n--;
        }

        res += (remains[1] + '0');
        return res;
    }
};