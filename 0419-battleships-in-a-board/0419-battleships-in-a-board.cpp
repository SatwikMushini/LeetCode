class Solution {
public:
    bool check(int i, int j, vector<vector<char>>& board, int m, int n){
        return ((i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.'));
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X' && check(i,j,board,m,n)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};