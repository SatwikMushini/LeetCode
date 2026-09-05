class Solution {
public:
    bool solve(int dis, auto& pos, int m){
        int currDis = 0;
        int st = 0;
        m--;   
        for(int i = 0; i < pos.size(); i++){
            currDis = pos[i] - pos[st];
            if(currDis >= dis){
                m--;
                st = i;
            }
            if(!m)break;
        }
        return m == 0;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int n = pos.size();

        int low = 1, high = pos[n-1] - pos[0];
        while(low <= high){
            int mid = (low + high) >> 1;
            if(solve(mid, pos, m))low = mid+1; 
            else high = mid-1;
        }
        return high;
    }
};