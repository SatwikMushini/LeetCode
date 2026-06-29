class Solution {
public:
    bool check(vector<int>&freq, int k){
        int maxi = 0, totalFreq = 0;
        for(auto x : freq){
            maxi = max(maxi, x);
            totalFreq += x;
        }
        return totalFreq - maxi <= k;
    }
    int characterReplacement(string s, int k) {
        vector<int>freq(26, 0);
        int left = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'A']++;
            if(check(freq, k))ans = max(ans, i - left + 1);
            else{
                freq[s[left] - 'A']--; left++;
            }
        }
        return ans;
    }
};