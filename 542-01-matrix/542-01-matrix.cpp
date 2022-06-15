class Solution {
public:
    
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0 and j>=0 and i<m and j<n;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(mat[i][j]==0)
                    q.push({i,j});
                else
                    mat[i][j] = -1;
            }
        }
        vector<int> dir = {0,-1,0,1,0};
        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int nr = dir[i] + r;
                int nc = dir[i+1] + c;
                if(!isValid(nr,nc,m,n) or mat[nr][nc]!=-1)
                    continue;
                mat[nr][nc] = mat[r][c] +1;
                q.push({nr,nc});
            }
        }
        return mat;
    }
};