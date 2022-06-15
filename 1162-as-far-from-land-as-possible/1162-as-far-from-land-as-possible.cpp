class Solution {
public:
    
    bool isValid(int i,int j,int n)
    {
        return i>=0 and j>=0 and i<n and j<n;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                if(grid[i][j])
                    q.push({i,j});
        int ans = 0;
        vector<int> dir = {0,-1,0,1,0};
        while(!q.empty())
        {
            int x0 = q.front().first;
            int y0 = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int x1 = x0+dir[i];
                int y1 = y0+dir[i+1];
                if(!isValid(x1,y1,n) or grid[x1][y1]!=0)
                    continue;
                grid[x1][y1] = grid[x0][y0] + 1;
                q.push({x1,y1});
                ans = max(ans,grid[x1][y1]);
            }
        }
        return ans>0?ans-1:-1;
    }
};