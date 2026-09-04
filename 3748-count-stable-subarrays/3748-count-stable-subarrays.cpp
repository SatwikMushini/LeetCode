typedef long long ll;
class Solution {
public:
    vector<ll> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> Idxs; //storing st indices of non-decreasing subarray.
        int n = nums.size();

        Idxs.push_back(0);
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1])Idxs.push_back(i+1);
        }
        Idxs.push_back(n);

        // for(auto x : Idxs)cout << x << " ";
        // cout << endl;

        vector<ll>pre(Idxs.size()); 
        for(int i = 1; i < Idxs.size(); i++){
            int len = Idxs[i] - Idxs[i-1];
            pre[i] = pre[i-1] + 1ll * (len) * (len + 1) / 2;
        }
        // for(auto x : pre)cout << x << " ";
        // cout << endl;

        vector<ll>res;
        for(auto q : queries){
            int l = q[0], r = q[1];
            if(l == r){
                res.push_back(1); continue;
            }

            if(Idxs.size() == 2){
                res.push_back(1ll*(r-l+1)*(r-l+2)/2);
                continue;
            }

            auto it1 = lower_bound(Idxs.begin(), Idxs.end(), q[0]);
            int lower = *it1;
            if (lower > r) {    // if entire query in one segment.
                ll len = r - l + 1;
                res.push_back(len * (len + 1) / 2);
                continue;
            }

            auto it2 = upper_bound(Idxs.begin(), Idxs.end(), q[1]); it2--;
            int upper = *it2;

            // cout << lower << " " << upper << endl;

            ll ans = 1LL * (lower - l) * (lower - l + 1) / 2
                    + 1LL * (r - upper + 1) * (r - upper + 2) / 2;  //left and right parts

            ans += 1ll * pre[it2 - Idxs.begin()] - pre[it1-Idxs.begin()]; //middle part

            res.push_back(ans);
        }
        
        return res;

    }
};