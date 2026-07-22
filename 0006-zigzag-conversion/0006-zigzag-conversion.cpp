class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(n == 1 || numRows == 1)return s;
        vector<string>store(numRows);
        int pos = 0; bool incre = true;
        for(int i = 0; i < n; i++){
            store[pos]+= s[i];
            pos = incre ? pos+1 : pos-1;
            if(pos >= numRows){
                pos = numRows-2; incre = false;
            }
            else if(pos < 0){
                pos = 1; incre = true;
            }
        }
        string res = "";
        for(auto x : store)res += x;
        return res;
    }
};