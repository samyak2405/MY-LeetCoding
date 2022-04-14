class Solution {
public:
    int numTrees(int n) {
if(n==0 or n==1)
            return 1;
        
        vector<int> v1(n+1,0);
        v1[0]=1,v1[1]=1;
        
        for(int i = 2;i<=n;i++){
            for(int j = 1;j<=i;j++)
                v1[i] +=v1[j-1]*v1[i-j];
        }
        for(auto it:v1)
            cout<<it<<" ";
        return v1[n];
    }
};