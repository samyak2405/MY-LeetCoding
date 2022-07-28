class Solution {
public:
    
    void f(int ind,string s,unordered_set<string> &s1,string tmp,vector<string> &res)
    {
        if(ind==s.length())
        {
            tmp.pop_back();
            res.push_back(tmp);
            return;
        }
        string store;
        for(int k = ind;k<s.length();k++)
        {
            store += s[k];
            if(s1.find(store)!=s1.end())
                f(k+1,s,s1,tmp+store+" ",res);
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_set<string> s1(wordDict.begin(),wordDict.end());
        f(0,s,s1,"",res);
        return res;
    }
};