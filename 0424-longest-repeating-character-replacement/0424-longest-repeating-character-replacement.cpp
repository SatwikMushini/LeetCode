class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26, 0);
        int ans = 0;
        int left = 0, maxFreq = 0;
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'A']++;
            maxFreq = max(maxFreq, freq[s[i] - 'A']);
            if((i - left + 1) - maxFreq <= k)ans = max(ans, i - left + 1);
            else{
                freq[s[left] - 'A']--; left++;
                maxFreq = *max_element(freq.begin(), freq.end());
            }
        }
        return ans;
    }
};