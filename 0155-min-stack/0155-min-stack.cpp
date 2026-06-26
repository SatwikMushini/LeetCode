class MinStack {
public:
    typedef long long ll;
    stack<ll> stk;
    ll mini;

    MinStack() {
        stk = stack<ll>();
        mini = INT_MAX;
    }
    
    void push(int value) {
        if(stk.empty()){
            stk.push(1ll*value);
            mini = 1ll*value;
            return;
        }
        if(value > mini)stk.push(1ll*value);
        else{
            stk.push(1ll* value * 2 - mini);
            mini = 1ll*value;
        }
    }
    
    void pop() {
        if(stk.top() <= mini){
            mini = 1ll*mini*2 - stk.top();
        }
        stk.pop();
    }
    
    int top() {
        if(stk.top() < mini)return mini;
        return stk.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */