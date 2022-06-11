class Solution {
public:
    
    void dfs(int i,int j,int n,int m,vector<vector<int>> &grid,int &cnt)
    {
        if(i<0 or j<0 or i==n or j==m or grid[i][j]==-1 or grid[i][j]==0)
            return;
        cnt++;
        grid[i][j] = -1;
        dfs(i+1,j,n,m,grid,cnt);
        dfs(i-1,j,n,m,grid,cnt);
        dfs(i,j+1,n,m,grid,cnt);
        dfs(i,j-1,n,m,grid,cnt);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int cnt = 0;
                if(grid[i][j] !=-1 or grid[i][j]!=0)
                {
                    dfs(i,j,n,m,grid,cnt);
                    max_cnt = max(max_cnt,cnt);
                }
            }
        }
        return max_cnt;
    }
};