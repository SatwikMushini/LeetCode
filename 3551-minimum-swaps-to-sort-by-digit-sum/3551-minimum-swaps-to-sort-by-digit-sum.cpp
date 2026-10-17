class Solution {
public:
    int sumi(int num) {
        int sum = 0;
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>numIdx(n);
        for(int i = 0; i < n; i++) {
            numIdx[i] = {nums[i], i};
        }
        sort(numIdx.begin(), numIdx.end(), [this](const pair<int,int>&a, const pair<int,int>&b) {
            int suma = sumi(a.first), sumb = sumi(b.first);
            if(suma == sumb)return a.first < b.first;
            return suma < sumb;
        });
        vector<bool>vis(n, false);
        int swaps = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] || numIdx[i].second == i)continue;

            int loopele = 0;
            int j = i;
            while(!vis[j]) {
                vis[j] = true;
                j = numIdx[j].second;
                loopele++;
            }
            swaps += loopele-1;
        }
        return swaps;
    }
};