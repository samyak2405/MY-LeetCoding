class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        vector<int> res;
        priority_queue<pair<int,int>>tmp;
        
        for(auto it:mp)
            tmp.push({it.second,it.first});
        
        while(k-- and !tmp.empty()){
            res.push_back(tmp.top().second);
            tmp.pop();
        }
        return res; 
    }
};