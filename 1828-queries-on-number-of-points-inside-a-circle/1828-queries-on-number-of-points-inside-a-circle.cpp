class Solution {
public:
    
    bool dist(int x0,int y0,int x1,int y1,int rad)
    {
        int a = x1-x0;
        int b = y1-y0;
        return a*a+b*b<=rad*rad;
    }
    
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res;
        for(int i = 0;i<n;i++)
        {
            int cnt = 0;
            int x0 = queries[i][0];
            int y0 = queries[i][1];
            int rad = queries[i][2];
            for(int j = 0;j<points.size();j++)
            {
                int x1 = points[j][0];
                int y1 = points[j][1];
                bool d = dist(x0,y0,x1,y1,rad);
                if(d)
                    cnt++;

            }
            res.push_back(cnt);
        }
        return res;
    }
};