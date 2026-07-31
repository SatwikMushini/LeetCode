class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        vector<int>freq(26, 0);
        for(auto x : word)freq[x - 'a']++;
        sort(freq.rbegin(), freq.rend());

        int steps = 0, ans = 0;
        for(int i = 0; i < 26; i++){
            if(i % 8 == 0)steps++;
            ans += freq[i] * steps;
        }

        return ans;
    }
};