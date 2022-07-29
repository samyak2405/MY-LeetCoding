class Solution {
public:
    
    int f(int ind,string s,unordered_set<string> &s1,vector<int> &dp)
    {
        if(ind==s.length())
            return 1;
        if(dp[ind]!=-1)
            return dp[ind];
        for(int k = ind;k<s.length();k++)
        {
            string tmp = s.substr(ind,k-ind+1);
            if(s1.find(tmp)!=s1.end() and f(k+1,s,s1,dp))
                return dp[ind] = 1;
        }
        return dp[ind] = 0;
    }
    
    static bool compare(string &s1,string &s2)
    {
        return s1.length()<s2.length();
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> s1;
        sort(words.begin(),words.end(),compare);
        for(int i = 0;i<words.size();i++)
        {
            string s = words[i];
            int n = s.length();
            vector<int> dp(n+1,-1);
            if(f(0,s,s1,dp))
                res.push_back(s);
            s1.insert(s);
        }
        return res;
    }
};