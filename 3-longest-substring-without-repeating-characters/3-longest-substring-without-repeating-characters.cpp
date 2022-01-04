class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0;
        vector<int> prev(256,-1);
        int j = 0;
        for(int i = 0;i<n;i++)
        {
            j = max(j,prev[s[i]]+1);
            int maxEnd = i - j + 1;
            res = max(res,maxEnd);
            prev[s[i]] = i;
        }
        return res;
    }
};