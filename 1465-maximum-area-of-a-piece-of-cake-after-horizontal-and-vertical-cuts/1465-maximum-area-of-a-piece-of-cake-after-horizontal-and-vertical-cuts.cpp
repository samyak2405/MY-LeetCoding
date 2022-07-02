class Solution {
    int mod = 1e9+7;
public:
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
        sort(hcuts.begin(),hcuts.end());
        sort(vcuts.begin(),vcuts.end());
        long long m1 = hcuts[0];
        for(int i = 1;i<hcuts.size();i++)
            m1 = max(m1,(long long)hcuts[i]-hcuts[i-1]);
        m1 = max(m1,(long long)h-hcuts[hcuts.size()-1]);
        long long m2 = vcuts[0];
        for(int i = 1;i<vcuts.size();i++)
            m2 = max(m2,(long long)vcuts[i]-vcuts[i-1]);
        m2 = max(m2,(long long)w-vcuts[vcuts.size()-1]);
        return ((m1%mod)*(m2%mod))%mod;
    }
            
};