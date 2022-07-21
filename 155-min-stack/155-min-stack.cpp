class MinStack {
    vector<int> stk,minstk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push_back(val);
        if(minstk.size()==0 or val<=minstk[minstk.size()-1])
            minstk.push_back(val);
        
    }
    
    void pop() {
        if(stk.size()>0 and stk[stk.size()-1]==getMin())
            minstk.pop_back();
        stk.pop_back();
    }
    
    int top() {
        return stk[stk.size()-1];
    }
    
    int getMin() {
        return minstk[minstk.size()-1];
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