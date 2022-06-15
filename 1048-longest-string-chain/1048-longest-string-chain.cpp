class Solution {
public:
    
    static bool compare(string &a,string &b)
    {
        return a.length()<b.length();
    }
    
    bool cmp(string &a,string &b)
    {
        int m = a.length();
        int n = b.length();
        if(m!=n+1)
            return false;
        int i = 0,j =0;
        while(i<m)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if(i==m and j==n)
            return true;
        return false;
    }
    
    int longestStrChain(vector<string>& word) {
        int n = word.size();
        sort(word.begin(),word.end(),compare);
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(cmp(word[i],word[j]))
                    dp[i] = max(dp[i],1+dp[j]);
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};