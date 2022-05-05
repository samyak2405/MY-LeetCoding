class MyStack {
public:
    queue<int> q1,q2;
    int top_e = -1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        top_e = x;
    }
    
    int pop() {
        while(!q1.empty() and q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int popped = q1.front();
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            if(q2.size()==1)
                top_e = q2.front();
            q2.pop();
        }
        return popped;
    }
    
    int top() {
        return top_e;
    }
    
    bool empty() {
        return q1.size()==0;
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