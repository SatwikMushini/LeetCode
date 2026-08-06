class Solution {
public:
    void rev(vector<char>& s, int idx){
        if(idx == s.size())return;
        char c = s[idx];
        rev(s, idx+1);
        s[s.size() - idx - 1] = c;
    }
    void reverseString(vector<char>& s) {
        rev(s, 0);
    }
};