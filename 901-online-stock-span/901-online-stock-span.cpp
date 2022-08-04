class StockSpanner {
    stack<pair<int,int>> s1;
    int cnt;
public:
    StockSpanner() {
        cnt = -1;
    }
    
    int next(int price) {
        cnt++;
        while(!s1.empty() and s1.top().first<=price)
            s1.pop();
        int ans = cnt+1;
        if(!s1.empty() and s1.top().first>price)
            ans = abs(cnt-s1.top().second);
        s1.push({price,cnt});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */