class MyQueue {
public:
    stack<int> s1,s2;
    int front_e = -1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty())
            front_e = x;
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty() and s1.size()>1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int popped = s1.top();
        s1.pop();
        while(!s2.empty())
        {
            if(s1.empty())
                front_e = s2.top();
            s1.push(s2.top());
            s2.pop();
        }
        return popped;
    }
    
    int peek() {
        return front_e;
    }
    
    bool empty() {
        return s1.size()==0;
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