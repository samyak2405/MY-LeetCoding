// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:

    int dfs(vector<vector<int>> &mat,int i,int j,int x,int y,int n,int m)
    {
        if(i<0 or j<0 or i==n or j==m or !mat[i][j] or mat[i][j]==-1)
            return INT_MIN;
        if(i==x and j==y)
            return 0;
        mat[i][j] = -1;
        int v1 = dfs(mat,i+1,j,x,y,n,m);
        int v2 = dfs(mat,i-1,j,x,y,n,m);
        int v3 = dfs(mat,i,j+1,x,y,n,m);
        int v4 = dfs(mat,i,j-1,x,y,n,m);
        mat[i][j] = 1;
        return 1 + max(v1,max(v2,max(v3,v4)));
    }

    int longestPath(vector<vector<int>> mat, int xs, int ys, int xd, int yd)
    {
        int n = mat.size();
        int m = mat[0].size();
        int res = dfs(mat,xs,ys,xd,yd,n,m);
        return res<0?-1:res;
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
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends