class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++){
            if(gas[i] - cost[i] >= 0){
                int curr = gas[i] - cost[i];
                int j = i+1;
                for(;j < n + i + 1; j++){
                    curr += gas[j % n];
                    if(curr >= cost[j % n])curr -= cost[j % n];
                    else break;
                }
                if(j == n+i+1)return i;
                if(j >= n)return -1;
                i = j;
            }
        }
        return -1;
    }
};