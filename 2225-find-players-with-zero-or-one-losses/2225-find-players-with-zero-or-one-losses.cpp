class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> winners;
        unordered_map<int,int> losers;

        for(int i = 0; i < matches.size(); i++){
            winners[matches[i][0]]++;
            losers[matches[i][1]]++;
        }

        vector<vector<int>> ans(2);

        for(auto &[player, wins]: winners){
            if(losers.count(player) == 0)ans[0].push_back(player);
            else{
                if(losers[player] == 1)ans[1].push_back(player);
            }
        }

        for(auto &[player, losses]: losers){
            if(winners.count(player) == 0 && losses == 1)ans[1].push_back(player);
        }
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};