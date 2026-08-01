class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int st = 0, currSum = 0, maxSum = 0;
        for(int i = 0; i < minutes; i++){
            if(grumpy[i])currSum += customers[i];
        }

        maxSum = currSum;
        int i = 0;
        for(int j = minutes; j < customers.size(); j++){
            if(grumpy[i] == 1)currSum -= customers[i];
            if(grumpy[j] == 1)currSum += customers[j];

            i++;
            if(currSum > maxSum){
                st = i; maxSum = currSum;
            }
        }

        for(int k = st; k < st + minutes; k++){
            grumpy[k] = 0;
        }

        int ans = 0;
        for(int i = 0; i < customers.size(); i++){
            if(grumpy[i] == 0){
                ans += customers[i];
            }
        }
        return ans;
    }
};