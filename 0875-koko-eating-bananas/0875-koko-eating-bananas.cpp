class Solution {
public:
    bool check(int k, vector<int>& piles, int h){
        int hrs = 0;
        for(auto &x : piles){
            hrs += (x + k - 1) / k;
        }
        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, piles, h)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};