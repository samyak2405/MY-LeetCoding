class Solution {
public:
    
    bool isSafe(int row,int col,vector<string> &board,int n)
    {
        int duprow = row;
        int dupcol = col;
        while(row<n and col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
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
        row = duprow;
        col = dupcol;
        while(row>=0 and col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        return true;
    }
    
    void solve(int col,vector<string> &board,int &cnt,int n)
    {
        if(n==col)
        {
            cnt++;
            return;
        }
        for(int row = 0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col] ='Q';
                solve(col+1,board,cnt,n);
                board[row][col] ='.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int cnt = 0;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0;i<n;i++)
            board[i] = s;
        solve(0,board,cnt,n);
        return cnt;
    }
};