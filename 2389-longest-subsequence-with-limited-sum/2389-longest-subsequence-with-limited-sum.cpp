class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int>prefix(n+1, 0);

        for(int i = 0; i < n; i++){      
            prefix[i+1] = prefix[i] + nums[i];
        }

        vector<int>ans;
        for(auto x : queries){      
            int low = 1, high = n;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(prefix[mid] > x)high = mid-1;
                else low = mid+1;
            }
            ans.push_back(high);
        }

        return ans;
    }
};