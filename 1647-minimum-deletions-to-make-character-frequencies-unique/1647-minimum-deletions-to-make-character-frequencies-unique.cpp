class Solution {
public:
    int minDeletions(string s) {
        int res = 0;
        map<char,int> mp;
        set<int> s1;
        for(auto it:s)
            mp[it]++;
        for(auto it:mp)
        {
            int tmp = it.second;
            while(s1.find(tmp)!=s1.end())
            {
                tmp--;
                res++;
            }
            if(tmp>0)
                s1.insert(tmp);
        }
        return res;
    }
};