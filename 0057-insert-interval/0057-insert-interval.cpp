class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();

        int i = 0;

        //pushing intervals less than new interval
        for(; i < n; i++){
            if(intervals[i][1] < newInterval[0])ans.push_back(intervals[i]);
            else break;
        }
        if(i == n){
            intervals.push_back(newInterval); return intervals;
        }

        //Checking if current interval has new interval st.. inside it or not
        if(intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]){
            intervals[i][1] = max(newInterval[1], intervals[i][1]);
            ans.push_back(intervals[i]);
        }
        else{
            ans.push_back(newInterval); 
        }

        //ignoring intervals inside newInterval
        for(; i < n; i++){
            if(ans.back()[1] >= intervals[i][1])continue;
            else break;
        }
        if(i == n)return ans;
       
       //checking if new interval end.. is inside current interval
        if(intervals[i][0] <= ans.back()[1]){
            ans.back()[1] = intervals[i][1]; i++;
        }
        for(; i < n; i++){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};