class Solution {
public:
    vector<int>seg;

    void build(int idx, auto& baskets, int st, int end) {
        if(st == end){
            seg[idx] = baskets[st];
            return;
        }

        int mid = (st + end) >> 1;
        build(2*idx+1, baskets, st, mid);
        build(2*idx+2, baskets, mid+1, end);

        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }

    int query(int idx, int st, int end, int fruitQ) {
        if(seg[idx] < fruitQ)return -1;
        if(st == end)return st;

        int mid = (st + end) >> 1;
        if(seg[2*idx+1] >= fruitQ){
            return query(2*idx+1, st, mid, fruitQ);
        }
        return query(2*idx+2, mid+1, end, fruitQ);
    }

    void update(int idx, int st, int end, int pos){
        if(st == end){
            seg[idx] = -1;
            return;
        }

        int mid = (st + end) >> 1;
        if(mid >= pos)update(2*idx+1, st, mid, pos);
        else update(2*idx+2, mid+1, end, pos);

        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();

        seg.assign(4 * n, 0);

        build(0, baskets, 0, n-1);

        int ans = 0;
        for(auto x : fruits){
            int pos = query(0, 0, n-1, x);

            if(pos != -1){
                update(0, 0, n-1, pos);
            }
            else ans++;
        }

        return ans;
    }
};