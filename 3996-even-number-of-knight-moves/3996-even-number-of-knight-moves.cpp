class Solution {
public:
    bool isValid(int x, int y){
        return (x >= 0 && x < 8 && y >= 0 && y < 8);
    }
    bool canReach(vector<int>& start, vector<int>& target) {
        queue<vector<int>>q;
        bool vis[8][8] = {0};

        q.push({start[0], start[1], 0});
        vis[start[0]][start[1]] = true;

        vector<pair<int,int>> dir = {{-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,-1},{2,1}, {-1,-2}, {1,-2}};
        while(!q.empty()){
            int x = q.front()[0], y = q.front()[1], cnt = q.front()[2];
            if(x == target[0] && y == target[1] && cnt % 2 == 0)return true;
            q.pop();
            for(auto &[i,j] : dir){
                if(isValid(x+i, y+j) && !vis[x+i][y+j]){
                    q.push({x+i, y+j, cnt+1});
                    vis[x+i][y+j] = true;
                }
            }
        }
        return false;
    }
};