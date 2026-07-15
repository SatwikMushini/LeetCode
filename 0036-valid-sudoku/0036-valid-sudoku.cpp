class Solution {
public:
    bool checkValid(vector<vector<char>>& board, int i, int j){
        for(int k = 0; k < 9; k++){
            if(k != j && board[i][k] == board[i][j])return false;
            if(k != i && board[k][j] == board[i][j])return false;
        }
        int boxRow = i / 3 * 3, boxCol = j / 3 * 3;
        for(int x = boxRow; x < boxRow+3; x++){
            for(int y = boxCol; y < boxCol+3; y++){
                if((x != i || y != j) && board[x][y] == board[i][j])return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(!checkValid(board, i, j))return false;
                }
            }
        }
        return true;
    }
};