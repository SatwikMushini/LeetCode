class Solution {
public:
    void give(string s, auto& freq, auto& ds){
        if(s.size() == 3 && (s.back()-'0') % 2 == 0){
            ds.insert(s);
            return;
        }
        for(int i = 0; i < 10; i++){
            if(!freq[i])continue;
            if(s.empty() && i == 0)continue;
            
            s += i + '0';
            freq[i]--;
            give(s, freq, ds);
            freq[i]++;
            s.pop_back();
        }
    }
    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10, 0);
        for(auto x : digits)freq[x]++;
        unordered_set<string>ds;
        give("", freq, ds);
        return ds.size();
    }
};