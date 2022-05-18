class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n,0);
        map<int,vector<int>> mp;
        for(auto it:pre)
        {
            mp[it[1]].push_back(it[0]);
        }
        for(int i = 0;i<pre.size();i++)
        {
            indegree[pre[i][0]]++; 
        }
        queue<int> q;
        for(int i = 0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);
        if(q.empty())
            return false;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:mp[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        for(int i = 0;i<n;i++)
            if(indegree[i]!=0)
                return false;
        return true;
    }
};