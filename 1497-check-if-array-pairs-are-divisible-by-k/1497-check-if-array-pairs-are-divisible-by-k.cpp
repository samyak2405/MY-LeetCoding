class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto it:arr)
            mp[(it%k+k)%k]++;
        for(auto it:arr)
        {
            int rem = (it%k+k)%k;
            if(rem==0)
            {
                if(mp[rem]%2)
                    return false;
            }
            else if(rem*2==k)
            {
                if(mp[rem]%2)
                    return false;
            }
            else
            {
                int fq1 = mp[rem];
                int fq2 = mp[k-rem];
                if(fq1!=fq2)
                    return false;
            }
        }
        return true;
    }
};