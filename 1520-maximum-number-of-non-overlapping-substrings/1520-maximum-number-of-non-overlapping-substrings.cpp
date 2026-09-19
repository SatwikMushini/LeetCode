class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int>firstIdx(26, -1), lastIdx(26, -1);

        for(int i = 0; i < n; i++){
            lastIdx[s[i] - 'a'] = i;
            if(firstIdx[s[i] - 'a'] == -1)firstIdx[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> ps;

        for(int i = 0; i < n; i++){
            if(firstIdx[s[i] - 'a'] != i)continue;

            int end = lastIdx[s[i] - 'a'];
            bool valid = true;

            for(int j = i; j <= end; j++){
                if(firstIdx[s[j] - 'a'] < i){
                    valid = false; break;
                }
                end = max(end, lastIdx[s[j] - 'a']);
            }

            if(valid)ps.push_back({i, end});
        }

        sort(ps.begin(), ps.end(), [](const pair<int,int>&a, const pair<int,int>&b){
            return a.second < b.second;
        });

        int back = -1;
        vector<string>res;

        for(auto &[st, end]: ps){
            if(st > back){
                res.push_back(s.substr(st, end - st + 1));
                back = end;
            }
        }

        return res;
    }
};