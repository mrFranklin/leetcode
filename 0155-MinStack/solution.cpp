class MinStack {
public:
    stack<int> v;
    stack<int> minStack;
    
    /** initialize your data structure here. */
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int x) {
        minStack.push(min(minStack.top(), x));
        v.push(x);
    }
    
    void pop() {
        minStack.pop();
        v.pop();
    }
    
    int top() {
        return v.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */