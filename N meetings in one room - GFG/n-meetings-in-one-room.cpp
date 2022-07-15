// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        int cnt = 1;
        vector<pair<int,int>> v1;
        for(int i = 0;i<n;i++)
            v1.push_back({end[i],start[i]});
        sort(v1.begin(),v1.end());
        int i = 0,j = 1;
        while(j<n)
        {
            if(v1[i].first<v1[j].second)
            {
                cnt++;
                i=j;
                j++;
            }
            else
                j++;
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends