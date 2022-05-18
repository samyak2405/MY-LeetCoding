class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int &cnt,bool &flag)
    {
        if(i<0 or j<0 or i==n or j==m or grid[i][j]!=1)
            return;
        cnt++;
        grid[i][j] = 2;
        if(i==0 or j==0 or i==n-1 or j==m-1)
            flag = true;
        dfs(grid,i+1,j,n,m,cnt,flag);
        dfs(grid,i-1,j,n,m,cnt,flag);
        dfs(grid,i,j+1,n,m,cnt,flag);
        dfs(grid,i,j-1,n,m,cnt,flag);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int cnt = 0;
                    bool flag = false;
                    dfs(grid,i,j,n,m,cnt,flag);
                    if(!flag)
                        sum+=cnt;
                }
            }
        }
        return sum;
    }
};