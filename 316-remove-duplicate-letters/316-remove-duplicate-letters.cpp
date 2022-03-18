class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp;
        string res = "";
        vector<int> vis(26,0);
        for(auto it:s)
            mp[it]++;
        
        for(auto it:s)
        {
            mp[it]--;
            if(vis[it-'a'])
                continue;
            while(res.back()>it and mp[res.back()])
            {
                vis[res.back()-'a']=0;
                res.pop_back();
            }
            res+=it;
            vis[it-'a'] = true;
        }
        return res;
    }
};