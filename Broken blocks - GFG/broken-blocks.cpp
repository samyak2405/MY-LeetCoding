// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

int f(int i,int j,int m,int n,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
    if(i<0 or j<0 or i==m or j==n or matrix[i][j]==-1)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int v1 = f(i+1,j-1,m,n,matrix,dp);
    int v2 = f(i+1,j,m,n,matrix,dp);
    int v3 = f(i+1,j+1,m,n,matrix,dp);
    return dp[i][j] = matrix[i][j] + max(v1,max(v2,v3));
}

int MaxGold(vector<vector<int>>&matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int res = 0;
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    for(int i = 0;i<n;i++)
    {
        res = max(res,f(0,i,m,n,matrix,dp));
    }
    return res;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends