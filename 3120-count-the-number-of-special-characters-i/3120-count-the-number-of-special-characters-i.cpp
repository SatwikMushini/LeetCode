class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>freq;
        for(auto &x : word)freq[x]++;
        int cnt = 0;
        for(int i = 'a'; i <= 'z'; i++){
            if(freq[(char)i] && freq[toupper((char)i)])cnt++;
        }
        return cnt;
    }
};