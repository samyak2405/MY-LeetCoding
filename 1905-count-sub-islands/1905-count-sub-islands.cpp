class Solution {
public:
    
    bool _dfs(int i,int j,int n,int m,vector<vector<int>> &grid2)
    {
        if(i<0 or j<0 or i==n or j==m or grid2[i][j]==0 or grid2[i][j]==-2)
            return true;
        if(grid2[i][j]==1)
            return false;
        grid2[i][j] = -2;
        bool f1 = _dfs(i+1,j,n,m,grid2);
        bool f2 = _dfs(i-1,j,n,m,grid2);
        bool f3 = _dfs(i,j+1,n,m,grid2);
        bool f4 =_dfs(i,j-1,n,m,grid2);
        return f1 and f2 and f3 and f4;
    }
    
    void dfs(int i,int j,int n,int m,vector<vector<int>> &grid1,vector<vector<int>> &grid2)
    {
        if(i<0 or j<0 or i==n or j==m or grid1[i][j]==0 or grid1[i][j]==-1)
            return;
        grid1[i][j] = -1;
        if(grid2[i][j]==1)
            grid2[i][j] = 2;
        dfs(i+1,j,n,m,grid1,grid2);
        dfs(i-1,j,n,m,grid1,grid2);
        dfs(i,j+1,n,m,grid1,grid2);
        dfs(i,j-1,n,m,grid1,grid2);
    }
     
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(grid1[i][j] !=-1 and grid1[i][j] !=0 )
                    dfs(i,j,n,m,grid1,grid2);
        
        int cnt = 0;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid2[i][j]!=0 and grid2[i][j]!=1 and grid2[i][j]!=-2)
                {
                    if(_dfs(i,j,n,m,grid2))
                        cnt++;
                }
            }
        }
        return cnt;
    }
};