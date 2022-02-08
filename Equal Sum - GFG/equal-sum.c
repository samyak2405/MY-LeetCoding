// { Driver Code Starts
// Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
// User function Template for C

char* equilibrium(int* arr, int n) {
    int sumi = arr[0];
    int sumj = arr[n-1];
    
    for(int i = 0,j = n-1;(i<n-1) ,(j>=0);)
    {
        if(sumi==sumj)
        {
            if(j-i==2)
                return "YES";
            i++;
            j--;
            sumi+=arr[i];
            sumj+=arr[j];
        }
        else if(sumi>sumj)
        {
            j--;
            sumj+=arr[j];
        }
        else
        {
            i++;
            sumi+=arr[i];
        }
    }
    return "NO";
}


// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, i;
        scanf("%d", &n);
        int a[n];
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        char *ans;
        ans = equilibrium(a, n);
        printf("%s \n", ans);
    }
    return 0;
}  // } Driver Code Ends