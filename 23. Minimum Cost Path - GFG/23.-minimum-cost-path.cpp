// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	#define tp pair<int,pair<int,int>> 
	
	bool isValid(int i,int j,int n,int m)
	{
	   return i>=0 and j>=0 and i<n and j<m;
	}
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        priority_queue<tp,vector<tp>,greater<tp>> pq;
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        pq.push({grid[0][0],{0,0}});
        vis[0][0] = grid[0][0];
        vector<int> movements = {0,-1,0,1,0};
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            int i = node.second.first,j = node.second.second,val = node.first;
            if(i==n-1 and j==m-1)
                return vis[n-1][m-1];
            for(int k = 0;k<4;k++)
            {
                int c_i = i+movements[k];
                int c_j = j+movements[k+1];
                if(isValid(c_i,c_j,n,m))
                {
                    if(vis[c_i][c_j]>val+grid[c_i][c_j])
                    {
                        vis[c_i][c_j] = val+grid[c_i][c_j];
                        pq.push({vis[c_i][c_j],{c_i,c_j}});
                    }
                }
            }
        }
        return vis[n-1][m-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends