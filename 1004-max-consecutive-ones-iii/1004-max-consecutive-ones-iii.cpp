class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> idxQ;
        int max1s = 0, left = 0;
        for(int i = 0; i < nums.size(); i++){
            if(!nums[i]){
                idxQ.push(i);
                if(idxQ.size() > k){
                    left = idxQ.front() + 1;
                    idxQ.pop(); 
                }
            }
            max1s = max(max1s, i - left + 1);
        }
        return max1s;
    }
};