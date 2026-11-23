class ProductOfNumbers {
public:
    vector<int>pp; //prefix product
    int last_zero;
    ProductOfNumbers() {
        pp.push_back(1);
        last_zero = -1;
    }
    
    void add(int num) {
        if(!num)last_zero = pp.size();
        int back = pp.back();
        if(back)pp.push_back(back * num);
        else pp.push_back(num);
    }
    
    int getProduct(int k) {
        int n = pp.size();
        if(n-k <= last_zero)return 0;
        if(!pp[n-k-1])return pp.back();
        return pp.back() / pp[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */