class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        unordered_map<string,vector<string>> maap;
        for(int i = 0;i<words.size();i++)
        {
            string s = words[i];
            unordered_map<char,int> mp;
            string res="";
            int cnt = 0;
            for(int j = 0;j<s.length();j++)
            {
                if(mp.find(s[j])!=mp.end())
                    res+=to_string(mp[s[j]]);
                else
                {
                    res+=to_string(cnt);
                    mp[s[j]]=cnt;
                    cnt++;
                }
            }
            maap[s].push_back(res);
        }
        unordered_map<char,int> mp1;
            string pat = "";
            int cnt = 0;
            for(int i = 0;i<pattern.length();i++)
            {
                if(mp1.find(pattern[i])!=mp1.end())
                    pat+=to_string(mp1[pattern[i]]);
                else
                {
                    pat+=to_string(cnt);
                    mp1[pattern[i]] = cnt;
                    cnt++;
                }
            }
        vector<string> res;
        for(auto it:maap)
        {
            for(auto itr:it.second)
            {
                if(itr==pat)
                    res.push_back(it.first);
            }
        }
        return res;
    }
};