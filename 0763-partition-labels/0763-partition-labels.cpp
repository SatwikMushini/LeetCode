class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int>ans;

        int pre[n][26];
        memset(pre, 0, sizeof(pre));

        pre[n-1][s[n-1] - 'a']++;
        for(int i = n-2; i >= 0; i--){      // n * 26
            for(int j = 0; j < 26; j++){
                pre[i][j] = pre[i+1][j];
            }
            pre[i][s[i] - 'a']++;
        }

        unordered_set<char>seen;
        int left = 0;

        for(int i = 0; i < n-1; i++){   // n * 26
            seen.insert(s[i]);
            bool valid = true;

            for(auto x : seen){
                if(pre[i+1][x - 'a']){
                    valid = false; break;
                }
            }

            if(valid){
                seen.clear();
                ans.push_back(i - left + 1);
                left = i+1;
            }
        }

        ans.push_back(n - left);
        return ans;
    }
};