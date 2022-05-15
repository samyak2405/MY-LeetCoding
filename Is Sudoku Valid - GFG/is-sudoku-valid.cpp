// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool checker(vector<vector<int>> board,int i,int j,int element)
    {
        for(int k = 0;k<9;k++)
        {
            if(k!=j)
            {
                if(board[i][k]==element)
                    return false;
            }
            if(k!=i)
            {
                if(board[k][j]==element)
                    return false;
            }
        }
        
        int row = 0;
        if(i>=0 and i<=2)
            row = 0;
        else if(i>=3 and i<=5)
            row = 3;
        else
            row = 6;
        
        int col = 0;
        if(j>=0 and j<=2)
            col = 0;
        else if(j>=3 and j<=5)
            col = 3;
        else
            col = 6;
        for(int k = row;k<row+3;k++)
        {
            for(int l = col;l<col+3;l++)
            {
                if(k==i and l==j)
                    continue;
                else if(board[k][l]==element)
                    return false;
            }
        }
        return true;
    }

    int isValid(vector<vector<int>> mat){
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(mat[i][j]==0)
                    continue;
                else if(!checker(mat,i,j,mat[i][j]))
                    return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends