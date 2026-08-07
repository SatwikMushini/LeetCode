class Solution {
public:
    int cnt = 0;
    bool check(int i, int n){
        return(i % n == 0 || n % i == 0);
    }
    void give(vector<int>& ds, vector<bool>& vis, int n){
        if(ds.size() == n){
            cnt++;
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i] && check(i, ds.size()+1)){
                vis[i] = true;
                ds.push_back(i);

                give(ds, vis, n);

                ds.pop_back();
                vis[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>ds; vector<bool>vis(n+1, 0);
        give(ds, vis, n);
        return cnt;
    }
};