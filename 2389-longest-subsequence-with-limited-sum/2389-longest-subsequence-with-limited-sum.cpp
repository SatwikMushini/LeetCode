class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++){
            nums[i] = nums[i] + nums[i-1];
        }
        int n2 = queries.size();
        vector<int> ans;
        for(int i = 0; i < n2; i++){
            int query = queries[i];
            int low = 0, high = n-1;
            int idx = -1;
            while(low < high){
                int mid = low + (high-low)/2;
                if(nums[mid] == query){
                    idx = mid;
                    break;
                }
                if(nums[mid] > query)high = mid-1;
                else low = mid+1;
            }
            if(idx != -1)ans.push_back(idx+1);
            //else if(nums[low] == query)ans.push_back(low+1);
            else{
                if(nums[low] > query)ans.push_back(low);
                else ans.push_back(low+1);
            }
        }
        return ans;
    }
};