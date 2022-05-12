// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
    bool dfs(vector<vector<int>> &grid,vector<vector<bool>> &vis,int i,int j,int m,int n)
    {
        if(i<0 or j<0 or i==m or j==n or grid[i][j]==0 or vis[i][j])
            return false;
        vis[i][j] =true;
        if(grid[i][j]==2)
            return true;
        if(dfs(grid,vis,i-1,j,m,n))
            return true;
        if(dfs(grid,vis,i+1,j,m,n))
            return true;
        if(dfs(grid,vis,i,j-1,m,n))
            return true;
        if(dfs(grid,vis,i,j+1,m,n))
            return true;
        return false;
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int start_i =-1,start_j = -1;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    start_i = i;
                    start_j = j;
                    break;
                }
                if(start_i!=-1)
                    break;
            }
        }
        if(start_i==-1)
            return false;
       
       if(dfs(grid,vis,start_i,start_j,m,n))
                return true;
       
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends