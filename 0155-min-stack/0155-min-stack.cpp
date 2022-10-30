class MinStack {
public:
    stack<int> s,z;
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(z.empty()||val<=z.top())
            z.push(val);
    }
    
    void pop() {
       if(z.top()==s.top())
           z.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
   return z.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */