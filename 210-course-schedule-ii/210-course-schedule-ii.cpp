class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> res;
        queue<int> q;
        map<int,vector<int>> mp;
        vector<int> indegree(n,0);
        for(int i = 0;i<pre.size();i++)
        {
            mp[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        for(int i = 0;i<n;i++)
            if(!indegree[i])
            {
                q.push(i);
                res.push_back(i);
            }
        if(q.empty())
            return res;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:mp[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                    res.push_back(it);
                }
            }
        }
        for(int i = 0;i<indegree.size();i++)
            if(indegree[i]!=0)
                return vector<int>();
        return res;
    }
};