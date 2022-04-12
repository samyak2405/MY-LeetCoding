class Solution {
public:
    
    int counter(vector<vector<int>> &board,int i,int j,int m,int n)
    {
        int cnt = 0;
        if(i-1>=0 and j-1>=0 and board[i-1][j-1]==1)
            cnt++;
        if(i-1>=0 and board[i-1][j]==1)
            cnt++;
        if(i-1>=0 and j+1<n and board[i-1][j+1]==1)
            cnt++;
        if(i>=0 and j+1<n and board[i][j+1]==1)
            cnt++;
        if(i+1<m and j+1<n and board[i+1][j+1]==1)
            cnt++;
        if(i+1<m and j<n and board[i+1][j]==1)
            cnt++;
        if(i+1<m and j-1>=0 and board[i+1][j-1]==1)
            cnt++;
        if(i>=0 and j-1>=0 and board[i][j-1]==1)
            cnt++;
        
        return cnt;    
    }
    
    void gameOfLife(vector<vector<int>>& board){
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> v1;
        for(int i = 0;i<m;i++)
        {
            vector<int> tmp;
            for(int j = 0;j<n;j++)
            {
                int cnt = counter(board,i,j,m,n);
                tmp.push_back(cnt);
            }
            v1.push_back(tmp);
        }
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int cnt = v1[i][j];
                if(cnt<2)
                    board[i][j]=0;
                else if(cnt==2 or cnt==3 and board[i][j]==1)
                    continue;
                else if(cnt==3 and board[i][j]==0)
                    board[i][j]=1;
                else if(cnt>3)
                    board[i][j]=0;
            }
        }
    }
};