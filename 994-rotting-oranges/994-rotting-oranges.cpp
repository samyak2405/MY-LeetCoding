class Solution {
public:
    
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0 and j>=0 and i<m and j<n;
    }
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> lvl(m,vector<int>(n,0));
        int fresh = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    lvl[i][j] = 0;
                }
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(!fresh)
            return 0;
        if(q.empty())
            return -1;
        int ans = 0;
        vector<vector<int>> movements= {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto it:movements)
            {
                int c_i = it[0] + i;
                int c_j = it[1] + j;
                if(!isValid(c_i,c_j,m,n) or grid[c_i][c_j]==0 or grid[c_i][c_j]==2)
                    continue;
                q.push({c_i,c_j});
                grid[c_i][c_j] = 2;
                fresh--;
                lvl[c_i][c_j] = lvl[i][j] + 1;
                ans = max(ans,lvl[c_i][c_j]);
            }
        }
        if(fresh!=0)
            return -1;
        return ans;
    }
};