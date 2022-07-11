// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:

    bool isValid(int i,int j,int n)
    {
        return i>=0 and j>=0 and i<n and j<n;
    }

	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    vector<vector<int>> grid(N+1,vector<int>(N+1));
	    grid[KnightPos[0]][KnightPos[1]] = 1;
	    int res = 0;
	    int dx[8] = {-2,-2,-1,-1,1,1,2,2};
	    int dy[8] = {-1,1,-2,2,-2,2,-1,1};
	    while(!q.empty())
	    {
	        int sz = q.size();
	        for(int i =0;i<sz;i++)
	        {
	            int x1 = q.front().first;
	            int y1 = q.front().second;
	            q.pop();
	            if(x1==TargetPos[0] and y1 == TargetPos[1])
	                return res;
	            for(int k = 0;k<8;k++)
	            {
	                int c_x1 = x1+dx[k];
	                int c_y1 = y1+dy[k];
	                if(!isValid(c_x1,c_y1,N+1) or grid[c_x1][c_y1])
	                    continue;
	                grid[c_x1][c_y1] = 1;
	                q.push({c_x1,c_y1});
	            }
	        }
	        res++;
	    }
	    return res;
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