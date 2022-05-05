class Solution {
public:
    
    int f(int i1,int j1,int i2,int j2,int n,vector<vector<int>> &grid,vector<vector<vector<vector<int>>>> &dp)
    {
        if(i1>=n or i2>=n or j1>=n or j2>=n or grid[i1][j1]==-1 or grid[i2][j2]==-1)
            return INT_MIN;
        if(dp[i1][j1][i2][j2]!=-1)
            return dp[i1][j1][i2][j2];
        if(i1==n-1 and j1==n-1)
            return dp[i1][j1][i2][j2] = grid[i1][j1];
        if(i2==n-1 and j2==n-1)
            return dp[i1][j1][i2][j2] = grid[i2][j2];
        int cherries;
        if(i1==i2 and j1==j2)
            cherries = grid[i1][j1];
        else
            cherries = grid[i1][j1]+grid[i2][j2];
        int v1 = f(i1+1,j1,i2+1,j2,n,grid,dp);
        int v2 = f(i1+1,j1,i2,j2+1,n,grid,dp);
        int v3 = f(i1,j1+1,i2+1,j2,n,grid,dp);
        int v4 = f(i1,j1+1,i2,j2+1,n,grid,dp);
        return dp[i1][j1][i2][j2] = cherries+max(v1,max(v2,max(v3,v4)));
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        int val=f(0,0,0,0,grid.size(),grid,dp);
        if(val<0)
            return 0;
        return val;
    }
};