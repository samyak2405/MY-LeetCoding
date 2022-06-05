class Solution {
public:
    
    bool isSafe(int row,int col,int n,vector<string> &board)
    {
        int duprow = row;
        int dupcol = col;
        while(row>=0 and col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        col = dupcol;
        while(row<n and col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int col,int n,int &cnt,vector<string> &board)
    {
        if(col==n)
        {
            cnt++;
            return;
        }
        for(int row = 0;row<n;row++)
        {
            if(isSafe(row,col,n,board))
            {
                board[row][col] = 'Q';
                solve(col+1,n,cnt,board);
                board[row][col] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string> board(n,s);
        int cnt = 0;
        solve(0,n,cnt,board);
        return cnt;
    }
};