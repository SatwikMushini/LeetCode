class Solution {
public:
    bool checkPali(string& s, int i, int j){
        int a = i, b = j;
        while(a <= b){
            if(s[a] != s[b])return false;
            a++; b--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        if(k == 1)return s.size();

        vector<pair<int,int>>p;
        int n = s.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(j-i+1 >= k && checkPali(s, i, j))p.push_back({i, j});
            }
        }

        if(p.empty())return 0;

        sort(p.begin(), p.end(), [](const pair<int,int>&a, const pair<int,int>&b){
            return a.second < b.second;
        });

        int back = p[0].second;
        int cnt = 1;

        for(int i = 1; i < p.size(); i++){
            if(p[i].first > back){
                cnt++;
                back = p[i].second;
            }
        }
        return cnt;
    }
};