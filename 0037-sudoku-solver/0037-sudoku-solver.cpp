class Solution {
public:
    bool possible(char num, int row, int col, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == num)return false;
            if(board[i][col] == num)return false;
            if(board[(row / 3) * 3 + (i / 3)][(col / 3) * 3 + (i % 3)] == num)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(int dig = 1; dig <= 9; dig++){
                        if(possible(dig+'0', i, j, board)){
                            board[i][j] = (dig + '0');
                            if(solve(board))return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};