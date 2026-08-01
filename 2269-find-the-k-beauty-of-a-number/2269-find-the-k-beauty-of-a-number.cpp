class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int i = 0, j = k;

        int ans = 0;
        for(int i = k; i < s.size()+1; i++){
            string substr = s.substr(i-k, k);
            int div = stoi(substr);
            cout << substr << " ";
            if(div != 0 && num % div == 0)ans++;
        }
        return ans;
    }
};