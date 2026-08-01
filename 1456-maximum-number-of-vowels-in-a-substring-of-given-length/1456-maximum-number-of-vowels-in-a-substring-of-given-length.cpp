class Solution {
public:
    bool checkVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowelCnt = 0;
        for(int i = 0; i < k; i++){
            if(checkVowel(s[i]))vowelCnt++;
        }

        int maxCnt = vowelCnt;
        int j = 0;
        for(int i = k; i < n; i++){
            if(checkVowel(s[j]))vowelCnt--;
            if(checkVowel(s[i]))vowelCnt++;
            maxCnt = max(maxCnt, vowelCnt);
            j++;
        }
        return maxCnt;
    }
};