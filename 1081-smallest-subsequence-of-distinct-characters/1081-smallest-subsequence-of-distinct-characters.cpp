class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        unordered_map<char,int> mp;
        for(auto it:s)
            mp[it]++;
        vector<int> vis(26,0);
        for(auto it:s)
        {
            mp[it]--;
            if(vis[it-'a'])
                continue;
            while(res.back()>it and mp[res.back()])
            {
                vis[res.back()-'a'] = 0;
                res.pop_back();
            }
            res+=it;
            vis[it-'a'] = 1;
        }
        return res;
    }
};