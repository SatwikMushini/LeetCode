class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        unordered_map<char,int>freq;
        int maxLen = 2;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
            while(freq[s[i]] == 3){
                freq[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};