// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    void lca(int x,vector<int> &lcax)
    {
        while(x>1)
        {
            if(x%2==0)
            {
                lcax.emplace_back(x/2);
                x/=2;
            }
            else
            {
                lcax.emplace_back((x-1)/2);
                x=(x-1)/2;
            }
        }
        // lcax.emplace_back(1);
    }

    int shortestPath( int x, int y){ 
        vector<int> lcax,lcay;
        lcax.emplace_back(x);
        lcay.emplace_back(y);
        lca(x,lcax);
        lca(y,lcay);
        map<int,int> mp;
        int ans = 0;
        // for(int i = 0;i<lcax.size();i++)
        //     cout<<lcax[i]<<" ";
        // cout<<endl;
        // for(int i = 0;i<lcay.size();i++)
        //     cout<<lcay[i]<<" ";
        for(int i = 0;i<lcax.size();i++)
            mp[lcax[i]] = i;
        for( int i = 0;i<lcay.size();i++)
            if(mp.find(lcay[i])!=mp.end())
            {
                // cout<<mp[lcay[i]]<<" "<<i<<" ";
                ans = mp[lcay[i]]+i;
                break;
            }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends