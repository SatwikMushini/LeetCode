class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
        int maxSum = lsum;
        int rIdx = cardPoints.size()-1;
        while(k){
            lsum = lsum - cardPoints[k-1] + cardPoints[rIdx];
            maxSum = max(maxSum, lsum);
            rIdx--; k--;
        }
        return maxSum;
    }
};