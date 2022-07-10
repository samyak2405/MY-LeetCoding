// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    #define vvi vector<vector<int>>
    #define vi vector<int>
    void dfs(vvi &grid,vi tmp,vvi &res,int i,int j,int n,int m)
    {
        if(i<0 or j<0 or i==n or j==m)
            return;
        tmp.push_back(grid[i][j]);
        if(i==n-1 and j==m-1)
            res.push_back(tmp);
        dfs(grid,tmp,res,i+1,j,n,m);
        dfs(grid,tmp,res,i,j+1,n,m);
        tmp.pop_back();
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> res;
        dfs(grid,vector<int>(),res,0,0,n,m);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends