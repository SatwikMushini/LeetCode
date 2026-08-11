class Solution {
public:
    bool check(int i, int j, int n){
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, pair<int,int>> pos;

        int num = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                    pos[num++] = {i,j};
            }
        }

        reverse(board.begin(), board.end());
        for(int i = 0; i < n; i++){
            if(i & 1){
                reverse(board[i].begin(), board[i].end());
            }
        }
        queue<pair<int,int>>q;
        set<pair<int,int>>seen;
        
        if(board[0][0] != -1){
            q.push(pos[board[0][0]]);
            seen.insert(pos[board[0][0]]);
        }
        else{
            q.emplace(0,0); seen.insert({0,0});
        }

        int cnt = 0;
        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                auto [r, c] = q.front(); q.pop();
                if(r == n-1 && c == n-1)return cnt;
                int i = r, j = c;
                for(int k = 0; k < 6; k++){
                    j++;
                    if(j >= n){
                        i++;
                        j = 0;
                    }
                    if(check(i,j,n)){
                        if(board[i][j] != -1){
                            if(!seen.count(pos[board[i][j]])){
                                q.push(pos[board[i][j]]);
                                seen.insert(pos[board[i][j]]);
                            }
                        }
                        else{
                            if(!seen.count({i,j})){
                                q.emplace(i,j); seen.insert({i, j});
                            }
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};