class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1;i<=n;i++)
            q.push(i);
        int cnt = 1;
        while(q.size()>1)
        {
            if(cnt!=k)
            {
                int p = q.front();
                q.pop();
                q.push(p);
                cnt++;
            }
            else
            {
                q.pop();
                cnt = 1;
            }
        }
        return q.front();
    }
};