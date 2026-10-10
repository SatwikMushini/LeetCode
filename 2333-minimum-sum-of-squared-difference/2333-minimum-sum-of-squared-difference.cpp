typedef long long ll;
class Solution {
public:
    void printpq(auto pq) {
        while(!pq.empty()) {
            auto [diff, i] = pq.top(); pq.pop();
            cout << diff << " " << i << endl;
        }
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        unordered_map<int,int>freqs;
        for(int i = 0; i < nums1.size(); i++){
            int diff = abs(nums1[i] - nums2[i]);
            if(diff > 0)freqs[diff]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto &[k,v]: freqs) {
            pq.push({k, v});
        }

        ll k = 1ll* k1 + k2;
        while(!pq.empty() && k) {
            auto [diff, freq] = pq.top(); pq.pop();
            if(diff == 0 || pq.empty()){
                pq.push({diff, freq});
                break;
            }

            auto [diff2, freq2] = pq.top(); pq.pop();
            ll rel_diff = diff - diff2;
        
            if(rel_diff * freq <= k) {
                k -= rel_diff * freq;
                pq.push({diff2, freq + freq2}); 
            }
            else {
                pq.push({diff2, freq2});
                pq.push({diff, freq});
                break;
            }
        }

        if(!pq.empty() && k > 0) {
            auto [diff, freq] = pq.top();
            pq.pop();

            int div = k / freq;
            diff -= div;
            k -= freq * div;

            if(diff > 0 && freq - k > 0)
                pq.push({diff, freq - k});

            if(diff > 0 && k > 0)
                pq.push({diff - 1, k});
        }
        
        printpq(pq);
        ll ans = 0;
        while(!pq.empty()) {
            auto [diff, freq] = pq.top(); pq.pop();
            ans += 1ll * diff * diff * freq;
        }
        return ans;
    }
};