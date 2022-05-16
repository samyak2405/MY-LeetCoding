class Solution {
public:
    
    bool isValid(vector<vector<char>> &board,int row,int col,char c)
    {
        for(int i = 0;i<9;i++)
        {
            if(board[i][col]==c)
                return false;
            if(board[row][i] ==c)
                return false;
        }
        int x0 = (row/3)*3,y0=(col/3)*3;
        for(int i = 0;i<3;i++)
            for(int j = 0;j<3;j++)
                if(board[x0+i][y0+j]==c)
                    return false;
        return true;
    }
    
    bool solver(vector<vector<char>> &board)
    {
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(board,i,j,c))
                        {
                            board[i][j] = c;
                            if(solver(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};