class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int,char> mp;
        int i = 0;
        for(auto it:indices)
        {
            mp[it] = s[i];
            i++;
        }
        string res = "";
        for(auto it:mp)
            res+=it.second;
        return res;
    }
};