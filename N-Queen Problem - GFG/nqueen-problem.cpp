// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isSafe(int row,int col,vector<string> &board,int n)
    {
        int duprow = row;
        int dupcol = col;
        while(row>=0 and col>=0)
        {
            if(board[row][col] == 'Q')
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
            if(board[row][col] =='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,int n,vector<vector<int>> &res,vector<string> &board,vector<int> &boardnum)
    {
        if(col==n)
        {
            res.emplace_back(boardnum);
            return;
        }
        for(int row = 0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col] = 'Q';
                boardnum[col] = row+1;
                solve(col+1,n,res,board,boardnum);
                board[row][col] = '.';
                boardnum[col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> boardnum(n,0);
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0;i<n;i++)
            board[i] = s;
        solve(0,n,res,board,boardnum);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends