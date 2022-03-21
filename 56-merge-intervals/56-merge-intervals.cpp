class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i = 0;
        while(i<intervals.size())
        {
            pair<int,int> p = {intervals[i][0],intervals[i][1]};
            pq.push(p);
            i++;
        }
        while(!pq.empty())
        {
            pair<int,int> p = pq.top();
            pq.pop();
            if(pq.empty())
            {
                pq.push(p);
                break;
            }
            pair<int,int> q = pq.top();
            pq.pop();
            if(p.second>=q.first)
            {
                pq.push({p.first,max(q.second,p.second)});
            }
            else if(p.second<q.first)
            {
                res.push_back(vector<int>{p.first,p.second});
                pq.push(q);
            }
        }
        while(!pq.empty())
        {
            res.push_back(vector<int>{pq.top().first,pq.top().second});
            pq.pop();
        }
        return res;
    }
};