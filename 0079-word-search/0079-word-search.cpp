class Solution {
public:
    bool give(int idx, vector<vector<char>>&board, int i, int j, string word, vector<vector<int>>&visited, int m, int n){
        if(idx == word.size())return true;
        if(i > 0 && !visited[i-1][j] && board[i-1][j] == word[idx]){
            visited[i-1][j] = 1;
            if(give(idx+1, board, i-1, j, word, visited, m, n))return true;
            visited[i-1][j] = 0;
        }
        if(i < m-1 && !visited[i+1][j] && board[i+1][j] == word[idx]){
            visited[i+1][j] = 1;
            if(give(idx+1, board, i+1, j, word, visited, m, n))return true;
            visited[i+1][j] = 0;
        }
        if(j > 0 && !visited[i][j-1] && board[i][j-1] == word[idx]){
            visited[i][j-1] = 1;
            if(give(idx+1, board, i, j-1, word, visited, m, n))return true;
            visited[i][j-1] = 0;
        }
        if(j < n-1 && !visited[i][j+1] && board[i][j+1] == word[idx]){
            visited[i][j+1] = 1;
            if(give(idx+1, board, i, j+1, word, visited, m, n))return true;
            visited[i][j+1] = 0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        int freq1 = 0, freqL = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0])freq1++;
                if(board[i][j] == word[word.size()-1])freqL++;
            }
        }
        if(freq1 > freqL){
            reverse(word.begin(), word.end());
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = 1;
                    if(give(1, board, i, j, word, visited, m, n))return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};