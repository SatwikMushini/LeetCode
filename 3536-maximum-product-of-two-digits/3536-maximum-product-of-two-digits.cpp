class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0, secondMaxi = 0;
        while(n){
            if(maxi < (n % 10)){
                secondMaxi = maxi;
                maxi = n % 10;
            }
            else secondMaxi = max(secondMaxi, n % 10);
            n /= 10;
        }
        return maxi * secondMaxi;
    }
};