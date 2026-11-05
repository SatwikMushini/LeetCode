class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for(auto x : arr1) {
            int ele = *lower_bound(arr2.begin(), arr2.end(), x-d);
            if(abs(ele - x) > d)cnt++;
        }
        return cnt;
    }
};