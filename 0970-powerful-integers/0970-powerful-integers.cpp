class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(x == 1 && y == 1){
            if(bound >= 2)return {2};
            else return {};
        }
        set<int>ans;
        int i = 0;
        if(x == 1){
            swap(x, y);
        }
        while(1){
            int sum1 = pow(x, i);
            if(sum1 > bound)break;
            int j = 0;
            while(1){
                int sum = sum1 + pow(y, j);
                if(sum <= bound)ans.insert(sum);
                else break;
                j++;
                if(y == 1)break;
            }
            i++;
        }
        vector<int>res(ans.begin(), ans.end());
        return res;
    }
};