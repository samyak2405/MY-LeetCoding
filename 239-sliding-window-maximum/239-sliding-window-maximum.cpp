class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> res;
        deque<int> q;
        int n = arr.size();
        int i = 0;
        
        for(i = 0;i<k;i++)
        {
            while(!q.empty() and (arr[i]>=arr[q.back()]))
                q.pop_back();
            q.push_back(i);
        }
        
        for(;i<n;i++)
        {
            res.push_back(arr[q.front()]);
            
            while(!q.empty() and (q.front()<=i-k))
                q.pop_front();
            
            while(!q.empty() and (arr[i]>=arr[q.back()]))
                q.pop_back();
            
            q.push_back(i);
        }
        res.push_back(arr[q.front()]);
        q.pop_front();
        
        return res;
    }
};