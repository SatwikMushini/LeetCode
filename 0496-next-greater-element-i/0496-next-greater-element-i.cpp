class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextG;
        stack<int> stk; 
        for(int i = nums2.size()-1; i >= 0; i--){
            while(!stk.empty() && stk.top() < nums2[i]){
                stk.pop();
            }
            nextG[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        vector<int> res;
        for(auto num : nums1){
            res.push_back(nextG[num]);
        }
        return res;
    }
};