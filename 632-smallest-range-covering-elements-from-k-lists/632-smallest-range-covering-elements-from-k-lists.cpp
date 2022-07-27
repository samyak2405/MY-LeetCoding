class Solution {
public:
    #define pii pair<int,int>
    #define pip pair<int,pii>
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        int n = nums.size();
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        int start = 0,end = 0,mini = INT_MAX,maxi = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            pq.push({nums[i][0],{i,1}});
            mini = min(mini,nums[i][0]);
            maxi =max(maxi,nums[i][0]);
        }
        start = mini;
        end = maxi;
        while(1)
        {
            auto it = pq.top();
            pq.pop();
            int x = it.second.first;
            int y = it.second.second;
            if(y==nums[x].size())
                break;
            maxi = max(maxi,nums[x][y]);
            pq.push({nums[x][y],{x,y+1}});
            mini = pq.top().first;
            if(maxi-mini<end-start)
            {
                start = mini;
                end = maxi;
            }
        }
        return {start,end};
    }
};