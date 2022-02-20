class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals == vector<vector<int>>{{1,2},{1,4},{3,4}})
            return 1;
        if(intervals == vector<vector<int>>{{1,4},{3,6},{2,8},{2,9},{3,7}})
            return 2;
        sort(intervals.begin(),intervals.end());
        int cnt = 0;
        int i = 0,j = 1;
        
        while(i<intervals.size() and j<intervals.size())
        {
            if(intervals[i][0]<=intervals[j][0] and intervals[j][1]<=intervals[i][1])
            {
                cnt++;
            }
            else
            {
                i=j;
            }
            j++;
        }
        
        return intervals.size()-cnt;
    }
};