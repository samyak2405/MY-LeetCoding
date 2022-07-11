// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    vector<int> res;
    sort(a,a+n);
    int min_ind = 0,max_ind = n-1;
    int max_element = a[n-1]+1;
    for(int i = 0;i<n;i++)
    {
        if(i%2==0)
        {
            a[i]+=(max_element*(a[max_ind]%max_element));
            max_ind--;
            // cout<<a[i]<<" ";
        }
        else
        {
            a[i]+=(max_element*(a[min_ind]%max_element));
            min_ind++;
            // cout<<a[i]<<" ";
        }
    }
    for(int i = 0;i<n;i++)
        a[i]/=max_element;
    // cout<<endl;
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        if(i%2==0)
            sum+=a[i];
        else
            sum-=a[i];
    }
    if(sum==0)
        return {-1};
    for(int i = 0;i<n;i++)
        res.push_back(a[i]);
    return res;
}
