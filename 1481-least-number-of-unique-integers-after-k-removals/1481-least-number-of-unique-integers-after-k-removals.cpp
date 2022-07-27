class Solution {
public:
    
    #define pi pair<int,int>
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto it:arr)
            mp[it]++;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:mp)
            pq.push(it.second);
        while(!pq.empty() and k>0)
        {
            int freq = pq.top();
            k-=freq;
            pq.pop();
        }
        cout<<k<<" ";
        if(k<0)
            return pq.size()+1;
        return pq.size();
    }
};