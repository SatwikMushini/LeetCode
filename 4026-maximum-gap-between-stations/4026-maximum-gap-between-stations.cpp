class Solution {
public:
    int maximumGap(string sk, string st) {
        int n = sk.size(), m = st.size();
        if(n == 1)return 0;
        
        vector<int> early(n), last(n);

        //early possible assign
        int j = 0;
        for(int i = 0; i < m; i++){
            if(sk[j] == st[i]){
                early[j] = i;
                j++;
            }
            if(j >= n)break;
        }
        
        //last possible assign
        j = n-1;
        for(int i = m-1; i >= 0; i--){
            if(sk[j] == st[i]){
                last[j] = i;
                j--;
            }
            if(j < 0)break;
        }

        int maxGap = 1;
        for(int i = 0; i < n-1; i++){
            maxGap = max(maxGap, last[i+1] - early[i]);
        }

        return maxGap;
        
    }
};