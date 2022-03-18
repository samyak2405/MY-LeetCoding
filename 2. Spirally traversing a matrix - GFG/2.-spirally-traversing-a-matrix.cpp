// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> res;
        
        int top = 0,down = r-1,left = 0,right = c-1,dir = 0;
        int cnt = r*c;
        while(cnt)
        {
            if(dir == 0)
            {
                for(int i = left;i<=right;i++)
                {
                    res.push_back(matrix[top][i]);
                    cnt--;
                }
                top++;
                dir = 1;
            }
            else if(dir == 1)
            {
                for(int i = top;i<=down;i++)
                {
                    res.push_back(matrix[i][right]);
                    cnt--;
                }
                right--;
                dir = 2;
            }
            else if(dir == 2)
            {
                for(int i = right;i>=left;i--)
                {
                    res.push_back(matrix[down][i]);
                    cnt--;
                }
                down--;
                dir = 3;
            }
            else if(dir == 3)
            {
                for(int i = down;i>=top;i--)
                {
                    res.push_back(matrix[i][left]);
                    cnt--;
                }
                left++;
                dir = 0;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends