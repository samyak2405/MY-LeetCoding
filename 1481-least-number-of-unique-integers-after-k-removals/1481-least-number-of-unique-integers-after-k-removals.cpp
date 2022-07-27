class Solution {
public:
    
    #define pi pair<int,int>
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto it:arr)
            mp[it]++;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        while(!pq.empty() and k>0)
        {
            int freq = pq.top().first;
            while(freq>0 and k>0)
            {
                freq--;
                k--;
            }
            if(freq==0)
                pq.pop();
        }
        return pq.size();
    }
};