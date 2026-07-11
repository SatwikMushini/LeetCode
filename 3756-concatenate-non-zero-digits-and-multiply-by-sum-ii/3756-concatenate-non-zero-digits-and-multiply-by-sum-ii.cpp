const int MOD = 1e9 + 7;
int pow10[100001];
int u = 0;
void run(){
    u = 1;
    pow10[0] = 1;
    for(int i = 1; i < 1e5+1; i++){
        pow10[i] = (1ll * pow10[i-1] * 10) % MOD;
    }
}

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        if(u == 0)run();
        int n = s.size();
        vector<int>ans;
        vector<int>add(n+1, 0), num(n+1, 0), digCnt(n+1, 0);   
        int prevVal = 0, prevAdd = 0, prevDigCnt = 0; 
        for(int i = 0; i < n; i++){
            int x = s[i] - '0';
            if(x){
                prevVal = (1ll * prevVal * 10 + x) % MOD;
                prevAdd = prevAdd + x;
                prevDigCnt += 1;
            }
            add[i+1] = prevAdd;
            num[i+1] = prevVal;
            digCnt[i+1] = prevDigCnt; 
        }
        for(auto query : queries){
            int l = query[0], r = query[1];
            int digSum = add[r+1] - add[l]; 
            int cnt = digCnt[r+1] - digCnt[l];
            int front = (1ll * num[l] * pow10[cnt]) % MOD;
            int back = num[r+1];
            int reqNum = (back - front + MOD) % MOD;
            ans.push_back((1ll * reqNum * digSum) % MOD);
        }
        return ans;
    }
};