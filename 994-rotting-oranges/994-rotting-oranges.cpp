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
        bool flag = false;
        queue<pair<int,int>> q;
        vector<vector<int>> lvl(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                    lvl[i][j] = 0;
                }
                if(grid[i][j]==1)
                    flag = true;
            }
        }
        if(!flag)
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
                int c_x = it[0] + i;
                int c_y = it[1] + j;
                if(!isValid(c_x,c_y,m,n))
                    continue;
                if(vis[c_x][c_y])
                    continue;
                if(grid[c_x][c_y]==0)
                    continue;
                q.push({c_x,c_y});
                grid[c_x][c_y] = 2;
                vis[c_x][c_y] = 1;
                lvl[c_x][c_y] = lvl[i][j] + 1;
                ans = max(ans,lvl[c_x][c_y]);
            }
        }
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                if(grid[i][j]==1)
                    return -1;
        return ans;
    }
};