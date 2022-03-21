class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        map<char,int> mp;
        for(int i = 0;i<s.length();i++)
            mp[s[i]] = i;
        int prev = -1;
        int max = INT_MIN;
        for(int i = 0;i<s.length();i++)
        {
            int x = mp[s[i]];
            if(max<x)
                max = x;
            if(max == i)
            {
                res.push_back(max-prev);
                prev = max;
                max = INT_MIN;
            }
        }
        return res;
    }
};