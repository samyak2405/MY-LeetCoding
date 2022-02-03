class Solution {
public:
    
    bool isAnagram(vector<int> &c1,vector<int> &c2)
    {
        for(int i = 0;i<256;i++)
        {
            if(c1[i]!=c2[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        vector<int> c1(256,0),c2(256,0);
        
        for(int i = 0;i<s1.length();i++)
        {
            c1[s1[i]]++;
            c2[s2[i]]++;
        }
        
        for(int i = s1.length();i<=s2.length();i++)
        {
            if(isAnagram(c1,c2))
                return true;
            c2[s2[i]]++;
            c2[s2[i-s1.length()]]--;
        }
        return false;
    }
};