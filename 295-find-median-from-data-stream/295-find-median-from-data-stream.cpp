class MedianFinder {
    
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    
public:
    MedianFinder()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
   
    }
    
    void balance()
    {
        int n = maxheap.size();
        int m = minheap.size();
        if(abs(n-m)==2)
        {
            if(n>m)
            {
                int element = maxheap.top();
                maxheap.pop();
                minheap.push(element);
            }
            else
            {
                int element = minheap.top();
                minheap.pop();
                maxheap.push(element);
            }
        }
    }
    
    void addNum(int num) {
        if(maxheap.empty() and minheap.empty())
            maxheap.push(num);
        else
        {
            if(maxheap.top()<num)
                minheap.push(num);
            else
                maxheap.push(num);
        }
        balance();
    }
    
    double findMedian() {
        int n = maxheap.size();
        int m = minheap.size();
        if((n+m)%2==0)
            return (maxheap.top()+minheap.top())/2.0;
        else
        {
            if(n>m)
                return maxheap.top();
            else
                return minheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */