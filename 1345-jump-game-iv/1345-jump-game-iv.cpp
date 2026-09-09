class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>>pos;

        for(int i = 0; i < n; i++){
            pos[arr[i]].push_back(i);
        }

        queue<int>q;
        q.push(0);
        vector<int>vis(n, 0);
        vis[0] = 1;

        int jumps = 0;
        while(!q.empty()){
            int qs = q.size();

            while(qs--){
                int currPos = q.front(); q.pop();
                if(currPos == n-1)return jumps;

                if(currPos - 1 >= 0 && !vis[currPos-1]){
                    q.push(currPos-1); vis[currPos-1] = 1;
                }
                if(currPos + 1 < n && !vis[currPos+1]){
                    q.push(currPos+1); vis[currPos+1] = 1;
                }
                
                for(auto x : pos[arr[currPos]]){
                    if(x != currPos && !vis[x]){
                        q.push(x); vis[x] = 1;
                    }
                }
                pos[arr[currPos]].clear();
            }
            jumps++;
        }
        return jumps;
    }
};