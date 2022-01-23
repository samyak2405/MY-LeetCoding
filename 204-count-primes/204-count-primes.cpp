class Solution {
public:
    int countPrimes(int n) {
        if(n==0 or n==1 or n==2)
            return 0;
        
        vector<bool> seive(n,0);
        
        for(int i = 2;i<n;i++)
            seive[i] = 1;
        
        for(int i = 2;i*i<n;i++)
            if(seive[i]==1)
                for(int j = i*i;j<n;j+=i)
                    seive[j] = 0;
        
        return count(seive.begin(),seive.end(),true);
    }
};