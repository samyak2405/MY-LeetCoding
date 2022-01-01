class Solution {
public:
    
    bool areAnagram(vector<int> &cp,vector<int> &ct)
    {
        for(int i = 0;i<256;i++)
        {
            if(cp[i]!=ct[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.length()<p.length())
            return res;
        int n = 256;
        vector<int> cp(n,0),ct(n,0);
        
        for(int i = 0;i<p.length();i++)
        {
            ct[s[i]]++;
            cp[p[i]]++;
        }
        
        for(int i = p.length();i<=s.length();i++)
        {
            if(areAnagram(ct,cp))
                res.push_back(i-p.length());
            ct[s[i]]++;
            ct[s[i-p.length()]]--;
        }
        
        return res;
    }
};