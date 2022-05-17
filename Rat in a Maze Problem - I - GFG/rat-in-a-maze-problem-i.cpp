// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void dfs(vector<vector<int>> &grid,int i,int j,int n,int m,string s,vector<string> &res)
    {
        if(i<0 or j<0 or i==n or j==m or grid[i][j]!=1)
            return;
        if(i==n-1 and j==m-1)
        {
            res.push_back(s);
        }
        grid[i][j] = -1;
        dfs(grid,i+1,j,n,m,s+'D',res);
        dfs(grid,i-1,j,n,m,s+'U',res);
        dfs(grid,i,j-1,n,m,s+'L',res);
        dfs(grid,i,j+1,n,m,s+'R',res);
        grid[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        vector<string> res;
        dfs(grid,0,0,n,n,"",res);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends