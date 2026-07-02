class Solution {
public:
    bool check(vector<int>& sfreq, vector<int>& tfreq, string t){
        for(int i = 0; i < 128; i++){
            if(sfreq[i] < tfreq[i])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size() < t.size())return "";
        vector<int>tfreq(128, 0);
        for(auto x : t){
            tfreq[x]++;
        }
        vector<int>sfreq(128, 0);
        int left = 0;
        int minWindow = 1e5, stIdx = -1;
        for(int i = 0; i < s.size(); i++){
            sfreq[s[i]]++;
            while(check(sfreq, tfreq, t)){
                if(i - left + 1 < minWindow){
                    stIdx = left;
                    minWindow = i - left + 1;
                }
                sfreq[s[left]]--;
                left++;
            }
        }
        return stIdx == -1 ? "" : s.substr(stIdx, minWindow);
    }
};