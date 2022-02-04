class Solution {
public:
    
    void solve(int k,int n,int index,vector<vector<int>> &res,vector<int> &tmp)
    {
        if(n<0)
            return;
        if(n==0)
        {
            if(tmp.size()==k)
                res.push_back(tmp);
            return;
        }
        for(int i = !tmp.size()?1:tmp.back()+1;i<=9;i++)
        {
            if(n-i<0) break;
            tmp.push_back(i);
            solve(k,n-i,i+1,res,tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        solve(k,n,0,res,tmp);
        return res;
    }
};