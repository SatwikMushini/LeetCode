class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int max4groups = 0;
        rs.push_back({INT_MAX, 10});
        sort(rs.begin(), rs.end());

        vector<bool>res(11, false); //reserved
        unordered_set<int>rows;
        for(int i = 0; i < rs.size()-1; i++){
            if(rs[i][0] != rs[i+1][0]){
                res[rs[i][1]] = true;
                bool seat2 = false, seat4 = false, seat6 = false;
                if(!res[2] && !res[3] && !res[4] && !res[5])seat2 = true;
                if(!res[4] && !res[5] && !res[6] && !res[7])seat4 = true;
                if(!res[6] && !res[7] && !res[8] && !res[9])seat6 = true;

                if(seat2 && seat6)max4groups += 2;
                else if(seat2 || seat4 || seat6)max4groups++;

                fill(res.begin(), res.end(), false);
                rows.insert(rs[i][0]);
            }
            else res[rs[i][1]] = true;
        }

        max4groups += (n - rows.size()) * 2;
        return max4groups;
    }
};