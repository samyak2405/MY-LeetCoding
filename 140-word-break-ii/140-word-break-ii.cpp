class Solution {
public:
    
    void f(string s,int ind,string tmp,unordered_set<string> &s1,vector<string> &res)
    {
        if(ind==s.length())
        {
            tmp.pop_back();
            res.push_back(tmp);
            return;
        }
        string store = "";
        for(int i = ind;i<s.length();i++)
        {
            store += s[i];
            if(s1.find(store)!=s1.end())
                f(s,i+1,tmp+store+" ",s1,res);
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> s1(wordDict.begin(),wordDict.end());
        vector<string> res;
        f(s,0,"",s1,res);
        return res;
    } 
    
   
};