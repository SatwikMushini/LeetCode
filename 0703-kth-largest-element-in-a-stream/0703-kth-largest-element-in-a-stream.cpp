class KthLargest {
public:
    int kk;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        sort(nums.rbegin(), nums.rend());
        for(int i = 0; i < nums.size(); i++){
            if(i == kk)break;
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > kk){pq.pop();}
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */