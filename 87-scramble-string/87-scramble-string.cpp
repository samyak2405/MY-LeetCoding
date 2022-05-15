class Solution {
public:
    
    bool Check(string s1,string s2,unordered_map<string,bool> &mp)
    {
        string key = s1+" "+s2;
        if(s1==s2)
            return mp[key] = true;
        if(mp.find(key)!=mp.end())
            return mp[key];
        int n = s1.length();
//         vector<int> cnt1(26,0);
//         for(int i = 0;i<n;i++)
//         {
//             cnt1[s1[i]-'a']++;
//             cnt1[s2[i]-'a']--;
//         }
//         for(int i = 0;i<26;i++)
//             if(cnt1[i]!=0)
//                 return mp[key] = false;
        
        for(int i = 1;i<=n-1;i++)
        {
            //swapped
            if(Check(s1.substr(0,i),s2.substr(n-i),mp) and Check(s1.substr(i),s2.substr(0,n-i),mp))
                return mp[key] = true;
            //Not swapped
            if(Check(s1.substr(0,i),s2.substr(0,i),mp) and Check(s1.substr(i),s2.substr(i),mp))
                return mp[key] = true;
        }
        return mp[key] = false;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())
            return false;
       
        if(s1==s2)
            return true;
        
        unordered_map<string,bool> mp;
        return Check(s1,s2,mp);
    }
};