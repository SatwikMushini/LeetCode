class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<char>seen;
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            if(seen.find(s[i]) != seen.end()){
                maxLen = max(maxLen, i - left);
                while(s[i] != s[left]){
                    seen.erase(s[left]); left++;
                }
                left++;
            }
            else seen.insert(s[i]);
        }
        maxLen = max(maxLen, (int)s.size() - left);
        return maxLen;
    }
};