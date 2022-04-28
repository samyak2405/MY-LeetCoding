// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans(2,0);
        vector<int> can1(N,0),can2(N,0);
        for(int i = 0;i<N;i++)
            can1[i] = candies[i];
        sort(can1.begin(),can1.end());
        can2 = can1;
        int min_cost = 0;
        for(int i = 0;i<can1.size();i++)
        {
            min_cost += can1[i];
            int t = K;
            while(t-- and can1.size()!=0)
                can1.pop_back();
        }
        ans[0] = min_cost;
        min_cost = 0;
        reverse(can2.begin(),can2.end());
        for(int i = 0;i<can2.size();i++)
        {
            min_cost += can2[i];
            int t = K;
            while(t-- and can2.size()!=0)
                can2.pop_back();
        }
        ans[1] = min_cost;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends