// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    #define vvi vector<vector<int>>
    
    void dfsLand(int i,int j,int n,int m,vvi &grid)
    {
        if(i<0 or j<0 or i==n or j==m or grid[i][j]!=1)
            return;
        grid[i][j] = 2;
        dfs(i+1,j,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i,j-1,n,m,grid);
    }
    
    void dfs(int i,int j,int n,int m,vvi &grid)
    {
        if(i<0 or j<0 or i==n or j==m or grid[i][j]!=1)
            return;
        grid[i][j] = -1;
        dfs(i+1,j,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i,j-1,n,m,grid);
    }
    int closedIslands(vector<vector<int>>& grid, int n, int m) {
        for(int i = 0;i<m;i++)
        {
            dfs(0,i,n,m,grid);
            dfs(n-1,i,n,m,grid);
        }
        for(int i = 0;i<n;i++)
        {
            dfs(i,0,n,m,grid);
            dfs(i,m-1,n,m,grid);
        }
        int cnt = 0;
        for(int i = 1;i<n-1;i++)
        {
            for(int j = 1;j<m-1;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,n,m,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}

  // } Driver Code Ends