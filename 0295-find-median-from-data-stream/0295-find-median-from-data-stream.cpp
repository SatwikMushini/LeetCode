class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    MedianFinder() {
        
    }
    void equalizer(){
        if(pq1.top() > pq2.top()){
            int pq1top = pq1.top(); pq1.pop();
            int pq2top = pq2.top(); pq2.pop();
            pq1.push(pq2top);
            pq2.push(pq1top);
        }
    }
    void addNum(int num) {
        if(pq1.empty())pq1.push(num);
        else if(pq2.empty()){
            pq2.push(num);
            equalizer();
        }
        else{
            if(pq1.size() <= pq2.size()){
                pq1.push(num);
                equalizer();
            }
            else{
                pq2.push(num);
                equalizer();
            }
        }
    }
    
    double findMedian() {
        if(pq1.size() > pq2.size())return pq1.top();
        return (1.0 * pq1.top() + pq2.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */