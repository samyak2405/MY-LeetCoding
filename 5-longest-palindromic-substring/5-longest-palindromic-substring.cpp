class Solution {
public:
    void solve(string s,int l,int r,int &max_len,int &st,int &end)
    {
        while(l>=0 and r<s.length())
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }
                else
                    break;
            }
        int len = r-l-1;
            if(len>max_len)
            {
                max_len = len;
                st = l+1;
                end = r-1;
            }
    }
    string longestPalindrome(string s) {
        if(s.length()<=1)
            return s;
        int max_len = 1;
        int n = s.length();
        int st = 0, end = 0;
        
        //Odd length
        for(int i = 0;i<n-1;i++)
        {
            solve(s,i,i,max_len,st,end);
            solve(s,i,i+1,max_len,st,end);
        }
        return s.substr(st,max_len);
    }
};