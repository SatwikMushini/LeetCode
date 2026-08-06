class Solution {
public:
    int mark(int x, int y, int r, vector<int>& seen, vector<vector<int>>& bombs){
        int cnt = 0;
        queue<vector<int>>q;
        q.push({x,y,r});

        while(!q.empty()){
            auto bomb = q.front(); q.pop();
            int xx = bomb[0], yy = bomb[1], rr = bomb[2];
            cnt++;
            for(int k = 0; k < bombs.size(); k++){
                auto &b = bombs[k];
                int i = b[0], j = b[1], rrr = b[2];
                if(seen[k])continue;
                
                long long dx = xx - i;
                long long dy = yy - j;
                if (dx * dx + dy * dy <= 1LL * rr * rr){
                    q.push({i, j, rrr});
                    seen[k] = 1;
                }
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int maxCnt = 1;
        for(int i = 0; i < bombs.size(); i++){
            vector<int>seen(bombs.size(), 0);
            seen[i] = 1;
            
            auto &bomb = bombs[i];
            int x = bomb[0], y = bomb[1], r = bomb[2];

            maxCnt = max(maxCnt, mark(x,y,r,seen,bombs));
        }

        return maxCnt;
    }
};