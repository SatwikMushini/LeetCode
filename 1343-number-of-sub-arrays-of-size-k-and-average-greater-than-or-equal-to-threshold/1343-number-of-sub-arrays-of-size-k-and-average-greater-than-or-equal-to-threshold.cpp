class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += arr[i];
        }
        int cnt = (sum / k >= th);
        for(int i = k; i < n; i++){
            sum -= arr[i - k]; sum += arr[i];
            cnt += (sum / k >= th);
        }
        return cnt;
    }
};