class MyStack {
public:
    queue<int> a;
    queue<int> b;
    MyStack() {
    
    }
    
    void push(int x) {
        b.push(x);
        while(!a.empty()){
            b.push(a.front());
            a.pop();
        }
        swap(a,b);
    }
    
    int pop() {
        int ans=a.front();
        a.pop();
        return ans;
    }
    
    int top() {
        return a.front();
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */