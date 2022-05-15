class Solution {
public:
    
    bool dfs(vector<vector<char>> &board,int i,int j,string &word,int n,int m)
    {
        if(!word.size())
            return true;
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]!=word[0])
            return false;
        char c = board[i][j];
        board[i][j]='*';
        string s = word.substr(1);
        bool res = dfs(board,i+1,j,s,n,m) or dfs(board,i-1,j,s,n,m) or dfs(board,i,j+1,s,n,m) or dfs(board,i,j-1,s,n,m);
        board[i][j] = c;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(dfs(board,i,j,word,n,m))
                    return true;
            }
        }
        return false;
    }
};