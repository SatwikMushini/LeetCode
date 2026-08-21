class Solution {
public:
    int numberOfSpecialChars(string word) {
        sort(word.rbegin(), word.rend());

        vector<int>freq(26, 0);
        int cnt = 0;

        for(auto x : word){
            if(x >= 'a' && x <= 'z')freq[x - 'a']++;
            else{
                if(freq[x - 'A'] != -1 && freq[x - 'A']){
                    cnt++;
                    freq[x - 'A'] = -1;
                }
            }
        }
        return cnt;
    }
};