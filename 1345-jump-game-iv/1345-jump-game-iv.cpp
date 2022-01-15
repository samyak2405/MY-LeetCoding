class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1)
            return 0;
        if(arr[0] == arr[n-1])
            return 1;
        
        map<int,vector<int>> mp;
        for(int i = 0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        int cnt = 0;
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            cnt++;
            int sz = q.size();
            for(int i = 0;i<sz;i++)
            {
                int j = q.front();
                q.pop();
                if(j-1>=0 and mp.find(arr[j-1])!=mp.end())
                    q.push(j-1);
                
                if(j+1<n and mp.find(arr[j+1])!=mp.end())
                {
                    if(j+1==n-1)
                        return cnt;
                    q.push(j+1);
                }
                
                if(mp.find(arr[j])!=mp.end())
                {
                    for(auto it:mp[arr[j]])
                    {
                        if(it!=j)
                        {
                            if(it==n-1)
                                return cnt;
                            q.push(it);
                        }
                    }
                }
             mp.erase(arr[j]);   
            }
        }
        
        return cnt;
    }
};