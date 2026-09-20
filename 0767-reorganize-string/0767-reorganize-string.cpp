class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26, 0);
        for(auto x : s)freq[x - 'a']++;

        priority_queue<pair<int,char>>pq;
        for(int i = 0; i < 26; i++){
            if(freq[i])pq.push({freq[i], i + 'a'});
        }

        if(pq.size() == 1){
            return (s.size() == 1 ? s : "");
        }
        
        string ans = "";

        while(pq.size() > 1){
            auto [f, c] = pq.top(); pq.pop();
            auto [ff, cc] = pq.top(); pq.pop();

            ans += c; ans += cc; 
            if(f > 1)pq.push({f-1, c});
            if(ff > 1)pq.push({ff-1, cc});
        }

        if(pq.empty())return ans;
        
        auto [f, c] = pq.top();
        if(f > 1 || ans.back() == c)return "";
        return ans+c;
    }
};