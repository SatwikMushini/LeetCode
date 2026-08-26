class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int cnt = 0; //1 cnt
        int i = 0, left = 0;

        while(s[i] == '0'){i++; left++;} if(i == n)return ""; // taking out front zeros
        for(; i < n; i++){
            if(s[i] == '1')cnt++;
            if(cnt == k)break;
        }
        if(cnt < k)return ""; //if given string has insufficient 1s
    
        string ans = s.substr(left, i - left + 1);
        i++;
        for(; i < n; i++){
            if(s[i] == '1')cnt++;
            while(cnt > k || s[left] == '0'){
                if(s[left] == '1')cnt--;
                left++;
            }
            if(i - left + 1 <= ans.size()){
                string curr = s.substr(left, i - left + 1);
                if(curr.size() < ans.size() || ans > curr)ans = curr;
            }
        }
        return ans;
    }
};