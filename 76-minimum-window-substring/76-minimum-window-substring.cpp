class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int j = 0;
        int x = 0;
        int y = INT_MAX;
        map<char,int> mp;
        for(auto it:t)
            mp[it]++;
        int cnt = mp.size();
        
        if(mp.find(s[j])!=mp.end())
        {
            mp[s[j]]--;
            if(mp[s[j]]==0)
                cnt--;
        }
        
        while(j<s.length())
        {   
            if(cnt>0)
            {
                j++;
                if(mp.find(s[j])!=mp.end())
                {
                    mp[s[j]]--;
                    if(mp[s[j]]==0)
                        cnt--;
                }
            }
            
            else if(cnt==0)
            {
                if(y>j-i+1)
                {
                    x = i;
                    y = j-i+1;
                }
            }
            while(cnt==0)
            {
                if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                    {
                        cnt++;
                        if(y>j-i+1)
                        {
                            x = i;
                            y = j-i+1;
                        }
                    }
                    i++;
                }
                else
                    i++;
            }   
        }
        string res ="";
        if(y==INT_MAX)
            return res;
        return res.append(s.substr(x,y));
}
};