class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())return "";
        unordered_map<int,int> mpp;
        for(auto x : t){
            mpp[x]++;
        }
        int left = 0;
        int minWindow = 1e5, stIdx = -1;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]--;
            if(mpp[s[i]] >= 0)cnt++;
            while(cnt == t.size()){
                if(i - left + 1 < minWindow){
                    stIdx = left;
                    minWindow = i - left + 1;
                }
                mpp[s[left]]++;
                if(mpp[s[left]] > 0)cnt--;
                left++;
            }
        }
        return stIdx == -1 ? "" : s.substr(stIdx, minWindow);
    }
};