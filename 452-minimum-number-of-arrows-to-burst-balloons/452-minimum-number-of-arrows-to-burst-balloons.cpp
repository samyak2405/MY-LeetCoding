class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int cnt = 1;
        int i = 0,j = i+1;
        while(j<points.size())
        {
            if(points[i][1]>=points[j][0] and points[i][1]>points[j][1])
            {
                i = j;
            }
            // else if(points[i][1]>=points[j][0] and points[i][1]<=points[j][1])
            //     j++;
            else if(points[i][1]<points[j][0])
            {
                cnt++;
                i = j;
            }
            j++;
        }
        return cnt;
    }
};