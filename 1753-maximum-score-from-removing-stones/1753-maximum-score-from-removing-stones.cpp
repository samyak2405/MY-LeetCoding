class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int cnt = 0;
        while(!pq.empty())
        {
            int sz = pq.size();
            if(sz==2 or sz==3)
            {
                int x = pq.top();
                pq.pop();
                int y = pq.top();
                pq.pop();
                cnt++;
                x--;
                y--;
                if(x!=0)
                    pq.push(x);
                if(y!=0)
                    pq.push(y);
            }
            else
            {
                break;
            }
        }
        return cnt;
    }
};