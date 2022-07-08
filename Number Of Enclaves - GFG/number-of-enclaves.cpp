// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    #define vvi vector<vector<int>>
  
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
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<m;i++)
            dfs(0,i,n,m,grid);
        for(int i = 0;i<m;i++)
            dfs(n-1,i,n,m,grid);
        for(int i = 0;i<n;i++)
            dfs(i,0,n,m,grid);
        for(int i = 0;i<n;i++)
            dfs(i,m-1,n,m,grid);
        int cnt = 0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(grid[i][j]==1)
                    cnt++;
        return cnt;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}  // } Driver Code Ends