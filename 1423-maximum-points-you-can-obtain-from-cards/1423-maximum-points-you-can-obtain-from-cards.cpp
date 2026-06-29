class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int>prefixSum(n, 0);
        prefixSum[0] = cardPoints[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + cardPoints[i];
        }
        if(n == k)return prefixSum[n-1];
        int maxScore = prefixSum[n-1] - prefixSum[n-k-1];
        for(int i = 0; i < k; i++){
            maxScore = max(maxScore, prefixSum[i] + prefixSum[n-1] - prefixSum[n-k+i]);
        }
        return maxScore;
    }
};