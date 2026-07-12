class KthLargest {
public:
    int kk;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(auto x : nums){
            pq.push(x);
            if(pq.size() > kk)pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.size() < kk || pq.top() < val){
            pq.push(val);
            if(pq.size() > kk)pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */