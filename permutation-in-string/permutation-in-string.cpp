class Solution {
public:
    
    bool areAnagram(vector<int> &ct,vector<int> &cp)
    {
        for(int i = 0;i<256;i++)
        {
            if(cp[i]!=ct[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        vector<int> ct(256,0),cp(256,0);
        for(int i = 0;i<s1.length();i++){
            ct[s2[i]]++;
            cp[s1[i]]++;
        }
        for(int i = s1.length();i<=s2.length();i++)
        {
            if(areAnagram(ct,cp))
                return true;
            ct[s2[i]]++;
            ct[s2[i-s1.length()]]--;
        }
        return false;
    } 
};