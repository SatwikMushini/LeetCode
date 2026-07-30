class Solution {
public:
    int query(vector<int>&bit, int idx){        //query to find the prefix sum, up until that pointt
        int sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int>bit(n+1, 0);

        for(int i = 0; i < n; i++){      //building fenwick tree
            int num = nums[i], j = i + 1;
            while(j <= n){
                bit[j] += nums[i];
                j += (j & -j);
            }
        }

        vector<int>ans;
        for(auto x : queries){      
            int low = 1, high = n;
            while(low <= high){
                int mid = low + (high - low) / 2;
                int sum = query(bit, mid);
                if(sum > x)high = mid-1;
                else low = mid+1;
            }
            ans.push_back(high);
        }

        return ans;
    }
};