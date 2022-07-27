class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        int n = nums.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
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
            if(it.second.second==nums[it.second.first].size())
                break;
            maxi = max(maxi,nums[it.second.first][it.second.second]);
            pq.push({nums[it.second.first][it.second.second],{it.second.first,it.second.second+1}});
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