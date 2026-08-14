int maximumLengthSubstring(char* s) {
    int n = strlen(s);
    int freq[26] = {0};
    int maxLen = 2;
    int left = 0;
    
    for(int i = 0; i < n; i++){
        freq[s[i] - 'a']++;
        while(freq[s[i] - 'a'] == 3){
            freq[s[left] - 'a']--;
            left++;
        }
        if(maxLen < i - left + 1)maxLen = i - left + 1;
    }
    return maxLen;
}