class Solution {
public:
    
    int f(vector<int> &piles,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int v1 = min(f(piles,i+1,j,dp),f(piles,i,j-1,dp));
        return dp[i][j] = max(piles[i]+f(piles,i+1,j,dp),piles[j]+f(piles,i,j-1,dp));
    }
    
    bool stoneGame(vector<int>& piles) {
        int total = 0;
        for(int i = 0;i<piles.size();i++)
            total+=piles[i];
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
        int alice = f(piles,0,piles.size()-1,dp);
        int bob = total - alice;
        return alice>bob;
    }
};