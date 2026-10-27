class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s = "";
        for(int i = 0; i < n; i++){
            s += '#';
        }
        vector<string>grid(m, s);
        int i = 0, j = 0;
        while(i < m){
            grid[i][j] = '.'; i++;
        }
        i--;
        while(j < n){
            grid[i][j] = '.'; j++;
        }
        return grid;
    }
};