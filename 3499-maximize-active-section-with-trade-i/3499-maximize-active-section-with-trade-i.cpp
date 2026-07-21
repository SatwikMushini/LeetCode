class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int left = 0, cnt = 0;
        int currentOnes = 0;
        for(auto x : s){
            if(x == '1')currentOnes++;
        }
        vector<pair<int,int>> blocks;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1])cnt++;
            else{
                blocks.push_back({left, cnt+1});
                cnt = 0;
                left = i+1;
            }
        }
        blocks.push_back({left, cnt+1});
        int maxChanges = 0;
        if(blocks.size() <= 2)return currentOnes;
        for(int i = 0; i < blocks.size()-2; i++){
            int pos1 = blocks[i].first, pos2 = blocks[i+1].first, pos3 = blocks[i+2].first;
            if(s[pos1] == '0' && s[pos2] == '1' && s[pos3] == '0'){
                maxChanges = max(maxChanges, blocks[i].second + blocks[i+2].second);
            }
        }
        return currentOnes + maxChanges;
    }
};