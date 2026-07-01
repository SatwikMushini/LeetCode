class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<int,int> mpp;
        int cnt = 0, left = 0;
        for(int i = 0; i < n; i++){
            mpp[s[i]]++;
            while(mpp.size() == 3){
                cnt += n - i;
                if(mpp[s[left]] == 1)mpp.erase(s[left]);
                else mpp[s[left]]--; 
                left++;
            } 
        }
        return cnt;
    }
};