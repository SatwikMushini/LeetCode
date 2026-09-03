class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int arrows = 1;
        auto &back = points[0];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > back[1]){
                arrows++;
                back = points[i];
            }
            else back[1] = min(back[1], points[i][1]);
        }
        return arrows;
    }
};