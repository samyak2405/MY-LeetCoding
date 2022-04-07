class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];
        priority_queue<int> pq;
        for(auto it:stones)
            pq.push(it);
        while(pq.size()>1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a==b)
                continue;
            else
            {
                pq.push(a-b);
            }
        }
        return pq.size()==0?0:pq.top();
    }
};