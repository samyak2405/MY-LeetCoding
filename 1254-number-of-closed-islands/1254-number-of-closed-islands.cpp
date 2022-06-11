class Solution {
public:
    
    void dfs(int i,int j,int n,int m,vector<vector<int>> &grid,bool &flag)
    {
        if(i<0 or j<0 or i==n or j==m or grid[i][j]==1 or grid[i][j]==-1)
            return;
        if(i==0 or j==0 or i==n-1 or j==m-1)
            flag = false;
        grid[i][j] = -1;
        dfs(i+1,j,n,m,grid,flag);
        dfs(i-1,j,n,m,grid,flag);
        dfs(i,j-1,n,m,grid,flag);
        dfs(i,j+1,n,m,grid,flag);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for(int i = 1;i<n-1;i++)
        {
            for(int j = 1;j<m-1;j++)
            {
                bool flag = true;
                if(grid[i][j]!=-1 and grid[i][j]!=1)
                {
                    dfs(i,j,n,m,grid,flag);
                    if(flag)
                        res++;
                }
            }
        }
        return res;
    }
};