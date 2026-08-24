class Solution {
public:
    bool check(int weight, vector<int>&weights, int days){
        int curr_weight = 0, daysRequired = 0;
        for(auto x : weights){
            if(curr_weight + x <= weight)curr_weight += x;
            else{
                daysRequired++;
                curr_weight = x;
            }
        }
        return daysRequired+1 <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1, high = 1e8;
        int max_weight = *max_element(weights.begin(), weights.end());
        while(low < high){
            int mid = low + (high - low) / 2;
            if(max_weight <= mid && check(mid, weights, days))high = mid;
            else low = mid+1;
        }
        return high;
    }
};