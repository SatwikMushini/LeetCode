class MyQueue {
public:
    stack<int>stk;
    stack<int>stk2;
    MyQueue() {
        stk = stack<int>();
    }
    
    void push(int x) {
        stk.push(x);
    }   
    
    int pop() {
        if(stk2.empty()){
            while(!stk.empty()){
                stk2.push(stk.top()); stk.pop();
            }
        }
        int front = stk2.top(); stk2.pop();
        return front;
    }
    
    int peek() {
        if(stk2.empty()){
            while(!stk.empty()){
                stk2.push(stk.top()); stk.pop();
            }
        }
        return stk2.top();
    }
    
    bool empty() {
        return stk.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */