class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r[9][9],c[9][9],s[3][3][9];
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        memset(s,0,sizeof(s));
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int number = board[i][j] -'0'-1;
                    if(r[i][number])
                        return false;
                    r[i][number] = 1;
                    if(c[j][number])
                        return false;
                    c[j][number] = 1;
                    if(s[i/3][j/3][number])
                        return false;
                    s[i/3][j/3][number] = 1;
                }
            }
        }
        return true;
    }
};