class Solution {
public:
    #define vvvi vector<vector<vector<double>>>
    #define vvi vector<vector<double>>
    #define vi vector<double>
    int dx[8] = {-2,-2,-1,-1,1,1,2,2};
    int dy[8] = {-1,1,2,-2,2,-2,-1,1};
    double dfs(int n,int k,int i,int j,vvvi &dp)
    {
        if(i<0 or j<0 or i>=n or j>=n)
            return 0;
        if(k==0)
            return 1.0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        double ans = 0;
        for(int l = 0;l<8;l++)
            ans+=0.125*dfs(n,k-1,i+dx[l],j+dy[l],dp);
        return dp[i][j][k] = ans;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vvvi dp(n,vvi(n,vi(k+1,-1)));
        return dfs(n,k,row,column,dp);
    }
};