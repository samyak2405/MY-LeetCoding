class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i = 0;i<words.size();i++)
            mp[words[i]]++;
        map<int,set<string>> mp1;
        for(auto it:mp)
            mp1[it.second].insert(it.first);
        vector<string> res;
        auto it = mp1.rbegin();
        while(it!=mp1.rend() and k>0)
        {
            auto itr = it->second.begin();
            while(itr!=it->second.end() and k--)
            {
                res.push_back(*itr);
                itr++;
            }
            it++;
        }
        return res;
    }
};