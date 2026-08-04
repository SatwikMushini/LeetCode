class Solution {
public:
    bool isVowel(char c){
        string vowels = "aeiou";
        return vowels.find(c) != string::npos;
    }
    int countVowelSubstrings(string word) {
        int l = 0, r = 0;
        int deleted = 0;
        int ans = 0;

        unordered_map<char, int> freq;

        while(r < word.size()){

            if(!isVowel(word[r])){
                freq.clear();
                deleted = 0;
                r++; l = r;
                continue;
            }

            freq[word[r]]++;
            if(freq.size() == 5){
                while(freq[word[l]] > 1){
                    freq[word[l]]--;
                    l++;
                    deleted++;
                }
                ans += deleted + 1;
            }
            
            r++;
        }
        return ans;
    }
};