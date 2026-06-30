class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0, size = word.size();
        for(auto x : patterns){
            int len = x.size();
            for(int i = 0; i <= size - len; i++){
                if(x[0] == word[i]){
                    if(x == word.substr(i, len)){
                        cnt++; break;
                    }
                }
            }
        }
        return cnt;
    }
};