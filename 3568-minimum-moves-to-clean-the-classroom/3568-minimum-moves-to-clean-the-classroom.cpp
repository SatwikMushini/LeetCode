class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >= 0 && i < m  && j >= 0 && j < n);
    }
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size(), n = classroom[0].size();
        int row = 0, col = 0;

        vector<vector<int>>id(m, vector<int>(n, -1)); int k = 0;
        for(int i = 0; i < classroom.size(); i++){
            for(int j = 0; j < classroom[i].size(); j++){
                if(classroom[i][j] == 'L')id[i][j] = k++;
                if(classroom[i][j] == 'S'){
                    row = i; col = j;
                }
            }
        }

        if(k == 0)return 0;

        queue<tuple<int,int,int,int>>q;
        q.push({row, col, energy, 0});
        vector<vector<vector<vector<bool>>>> seen(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << k, false)
                )
            )
        );

        int moves = 0;
        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                auto [i, j, e, mask] = q.front(); q.pop();
                if(!isValid(i,j,m,n) || classroom[i][j] == 'X' || e < 0)continue;

                if(classroom[i][j] == 'R')e = energy;

                int nmask = mask;
                if(classroom[i][j] == 'L')nmask = (mask | (1 << id[i][j]));

                if(seen[i][j][e][nmask])continue;

                if(nmask == ((1 << k) - 1))return moves;

                seen[i][j][e][nmask] = true;

                q.push({i-1,j,e-1,nmask});
                q.push({i,j+1,e-1,nmask});
                q.push({i+1,j,e-1,nmask});
                q.push({i,j-1,e-1,nmask});
            }
            moves++;
        }
        return -1;
    }
};