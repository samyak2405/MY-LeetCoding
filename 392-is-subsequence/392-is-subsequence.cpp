class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n>m)
            return false;
        int i = 0, j = 0;
        while(i<n and j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        return i==n;
    }
};