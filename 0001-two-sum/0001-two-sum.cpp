class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> res;
        // multimap<int,int> mpp;
        // int size = nums.size();
        // for(int i = 0; i < size; i++){
        //     mpp.insert({nums[i], i});
        // }
        // for(int i = 0; i < size; i++){
        //     int x = nums[i];
        //     int y = target - x;
        //     auto it1 = mpp.find(x);
        //     mpp.erase(it1);
        //     auto it = mpp.find(y);
        //     if(it != mpp.end()){
        //         res.push_back(i);
        //         res.push_back(it->second);
        //         break;
        //     }
        // }
        // return res;
        int size = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < size; i++){
            int y = target - nums[i];
            if(mpp.find(y) != mpp.end()){
                return {i, mpp[y]};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};