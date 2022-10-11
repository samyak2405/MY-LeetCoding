//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
        vector<pair<pair<int,int>,int>> tmp;
        for(int i = 0;i<n;i++)
        {
            int a,b,c;
            a = height[i];
            b = width[i];
            c = length[i];
            tmp.push_back({{a,b},c});
            tmp.push_back({{b,a},c});
            tmp.push_back({{b,c},a});
            tmp.push_back({{c,b},a});
            tmp.push_back({{a,c},b});
            tmp.push_back({{c,a},b});
            sort(tmp.begin(),tmp.end());
        }
        sort(tmp.begin(),tmp.end());
        vector<int> dp(tmp.size(),0);
        int m = INT_MIN;
        for(int i = 0;i<tmp.size();i++)
        {
            dp[i] = tmp[i].second;
            for(int j = 0;j<i;j++)
            {
                if(tmp[i].first.first>tmp[j].first.first and tmp[i].first.second>tmp[j].first.second)
                    dp[i] = max(dp[i],dp[j]+tmp[i].second);
            }
            m = max(m,dp[i]);
        }
        // int m = INT_MIN;
        // for(int i = 0;i<tmp.size();i++)
        //     m = max(m,dp[i]);
        return m;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends