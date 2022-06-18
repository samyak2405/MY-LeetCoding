// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    
    bool isValid(int i,int j,int n,int m)
    {
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        vector<vector<int>> lvl(n,vector<int>(m,0));
        //push all sources in the queue and keep the count of fresh oranges
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        //if oranges are not fresh
        if(!fresh)
            return 0;
        //if no rotten oranges are present
        if(q.empty())
            return -1;
        int ans = INT_MIN;
        //do a multisource bfs traversal
        int movements[5] = {0,-1,0,1,0};
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k = 0;k<4;k++)
            {
                int c_i = i+movements[k];
                int c_j = j+movements[k+1];
                if(!isValid(c_i,c_j,n,m) or grid[c_i][c_j]==2 or grid[c_i][c_j]==0)
                    continue;
                grid[c_i][c_j] = 2;
                q.push({c_i,c_j});
                fresh--;
                lvl[c_i][c_j] = lvl[i][j]+1;
                ans = max(ans,lvl[c_i][c_j]);
            }
        }
        if(fresh)
            return -1;
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends