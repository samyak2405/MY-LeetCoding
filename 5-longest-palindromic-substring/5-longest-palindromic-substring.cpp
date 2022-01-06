class Solution {
public:
    
    void max_para(int l,int r,int &max_len,int &st,int &end)
    {
        int len = r-l-1;
            if(len>max_len)
            {
                max_len = len;
                st = l+1;
                end = r-1;
            }
    }
    
    void solve(string s,int &l,int &r,int n)
    {
        while(l>=0 and r<n)
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }
                else
                    break;
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
            int l = i,r = i, p = i,q = i+1;
            solve(s,l,r,n);
            max_para(l,r,max_len,st,end);
            solve(s,p,q,n);
            max_para(p,q,max_len,st,end);
        }
        return s.substr(st,max_len);
    }
};