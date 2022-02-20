class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt = 0, l = -1,r = -1;
        sort(intervals.begin(),intervals.end());
        for(auto it:intervals)
        {
            if(it[0]>l and it[1]>r)
                cnt++,l = it[0];
            r = max(r,it[1]);
        }
        return cnt;
    }
};