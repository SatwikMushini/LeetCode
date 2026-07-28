class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size() == 1)return s;

        vector<int>freq(26, 0);
        for(auto x : s)freq[x - 'a']++;

        string ans = "";
        char middle = 'A';

        for(int i = 0; i < 26; i++){
            if(freq[i] & 1){
                middle = i + 'a';
            }
            int cnt = freq[i] / 2;
            ans.append(cnt, i+'a');
        }

        string rev = ans;
        reverse(rev.begin(), rev.end());

        if(middle != 'A') ans += middle;

        ans += rev;
        return ans;
    }
};