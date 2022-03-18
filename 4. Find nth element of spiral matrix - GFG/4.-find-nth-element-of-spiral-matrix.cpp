// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}// } Driver Code Ends


/*You are required to complete this method*/
int findK(int A[MAX][MAX], int n, int m, int k)
{
    // if(m==1)
    //     return A[n-1][k-1];
    // if(n==1)
    //     return A[k-1][m-1];
    int top = 0,down = n-1,left = 0,right = m-1;
    int dir = 0;
    // k = k%(n*m);
    int element = 0;
    while(k)
    {
        if(dir == 0)
        {
            for(int i = left;i<=right and k;i++)
            {
                element = A[top][i];
                k--;
            }
            top++;
            dir = 1;
        }
        else if(dir == 1)
        {
            for(int i = top;i<=down and k;i++)
            {
                element = A[i][right];
                k--;
            }
            right--;
            dir = 2;
        }
        else if(dir == 2)
        {
            for(int i = right;i>=left and k;i--)
            {
                element = A[down][i];
                k--;
            }
            down--;
            dir = 3;
        }
        else if(dir == 3)
        {
            for(int i = down;i>=top and k;i--)
            {
                element = A[i][left];
                k--;
            }
            left++;
            dir = 0;
        }
    }
    return element;
}

