class Solution {
public:
    
    void backtrack(string s,vector<string> &res,int open,int close,int n)
    {
        if(s.length()==2*n)
        {
            res.push_back(s);
            return;
        }
        if(open<n)
            backtrack(s+'(',res,open+1,close,n);
        if(close<open)
            backtrack(s+')',res,open,close+1,n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("",res,0,0,n);
        return res;
    }
};