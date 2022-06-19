// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    bool isValid(int i,int j,int n)
    {
        return i>=0 and j>=0 and i<n and j<n;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    vector<vector<int>> grid(n+1,vector<int>(n+1,0));
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    grid[KnightPos[0]][KnightPos[1]] = 1;
	    int res = 0;
	    int row[8] = {-2,-2,1,-1,2,2,-1,1};
	    int col[8] = {-1,1,-2,-2,-1,1,2,2};
	    while(!q.empty())
	    {
	        int sz = q.size();
	        for(int i = 0;i<sz;i++)
	        {
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            if(x==TargetPos[0] and y == TargetPos[1])
	                return res;
	            for(int i = 0;i<8;i++)
	            {
	                int c_x = x + row[i];
	                int c_y = y + col[i];
	                if(!isValid(c_x,c_y,n+1) or grid[c_x][c_y]==1)
	                    continue;
	                q.push({c_x,c_y});
	                grid[c_x][c_y] = 1;
	            }
	        }
	        res++;
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends