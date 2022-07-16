class Solution {
public:
    #define vvvi vector<vector<vector<int>>>
    #define vvi vector<vector<int>>
    #define vi vector<int>
    int mod = 1e9+7;
    int dfs(vvvi &grid,int m,int n,int i,int j,int k)
    {
        if(i<0 or j<0 or i==m or j==n)
            return 1;
        if(k==0)
            return 0;
        if(grid[i][j][k]!=-1)
            return grid[i][j][k];
        int ans = 0;
        ans = (ans+dfs(grid,m,n,i+1,j,k-1))%mod;
        ans = (ans+dfs(grid,m,n,i-1,j,k-1))%mod;
        ans = (ans+dfs(grid,m,n,i,j-1,k-1))%mod;
        ans = (ans+dfs(grid,m,n,i,j+1,k-1))%mod;
        return grid[i][j][k] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vvvi grid(m+1,vvi(n+1,vi(maxMove+1,-1)));
        return dfs(grid,m,n,startRow,startColumn,maxMove);
    }
};