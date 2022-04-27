class Solution {
public:
    
    static bool comparator(string &a,string &b)
    {
        return a.length()<b.length();
    } 
    
    bool cmp(string &a,string &b)
    {
        int m = a.length();
        int n = b.length();
        if(m!=n+1)
            return false;
        int i = 0,j = 0;
        while(i<m)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(i==m and j==n)
            return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;
        sort(words.begin(),words.end(),comparator);
        for(int i = 0;i<n;i++)
        {
            for(int prev = 0;prev<i;prev++)
            {
                if(cmp(words[i],words[prev]) and 1+dp[prev]>dp[i])
                {
                    dp[i] = 1+dp[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};