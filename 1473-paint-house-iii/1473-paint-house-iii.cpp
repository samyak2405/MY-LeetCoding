class Solution {
    
public:
    #define vvvi vector<vector<vector<int>>> 
    #define vvi vector<vector<int>>
    #define vi vector<int>
    int f(int index,int prevColor,int neighbourCount,vi &house,vvi &cost,int m,int n,int target,vvvi &dp)
    {
        if(index==m)
            return neighbourCount==target?0:1e9;
        if(neighbourCount>target)
            return 1e9;
        if(dp[index][prevColor][neighbourCount]!=-1)
            return dp[index][prevColor][neighbourCount];
        int minCost = 1e9;
        if(house[index])
        {
            int neighbourhoodCount = neighbourCount + (prevColor!=house[index]);
            minCost = f(index+1,house[index],neighbourhoodCount,house,cost,m,n,target,dp);
        }
        else
        {
            for(int i = 1;i<=n;i++)
            {
                int neighbourHoodCount = neighbourCount + (prevColor!=i);
                int currCost = cost[index][i-1] + f(index+1,i,neighbourHoodCount,house,cost,m,n,target,dp);
                minCost = min(minCost,currCost);
            }
        }
        return dp[index][prevColor][neighbourCount] = minCost;
    }
    
    int minCost(vi& houses, vvi& cost, int m, int n, int target) {
        int ind = houses.size();
        vvvi dp(ind+1,vvi(n+1,vi(target+1,-1)));
        int ans = f(0,0,0,houses,cost,m,n,target,dp);
        return ans==1e9?-1:ans;
    }
};