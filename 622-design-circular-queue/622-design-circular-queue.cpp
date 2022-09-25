class MyCircularQueue {
    int cnt;
    deque<int> q;
public:
    MyCircularQueue(int k) {
        cnt = k;
    }
    
    bool enQueue(int value) {
        if(!isFull())
        {
            q.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        else
        {
            q.pop_front();
            return true;
        }
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return q.front();
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return q.back();
    }
    
    bool isEmpty() {
        if(!q.size())
            return true;
        return false;
    }
    
    bool isFull() {
        if(q.size()==cnt)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */