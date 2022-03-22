class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        sort(intervals.begin(),intervals.end());
        
        vector<int> tmp = intervals[0];
        vector<vector<int>> res;
        
        for(auto it:intervals)
        {
            if(it[0]<=tmp[1])
            {
                tmp[1] = max(it[1],tmp[1]);
            }
            else
            {
                res.emplace_back(tmp);
                tmp = it;
            }
        }
        res.emplace_back(tmp);
        return res;
    }
};