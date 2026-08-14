class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int freq[26] = {0};
        int maxLen = 2;
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            while(freq[s[i] - 'a'] == 3){
                freq[s[left] - 'a']--;
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};