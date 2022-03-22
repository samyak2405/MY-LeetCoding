class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        if(!mat.size())
            return res;
        int n = mat.size(),m = mat[0].size();
        
        for(int i = 0;i<=n+m-2;i++)
        {
            for(int j = 0;j<=i;j++)
            {
                int k = j;
                int l = i-k;
                if(!(i%2))
                    swap(k,l);
                if(k>=n or l>=m)
                    continue;
                res.push_back(mat[k][l]);
            }
        }
        
        return res;
    }
};