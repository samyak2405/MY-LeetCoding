class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,long long int> mp;
        int mod = 1e9+7;
        for(int i = 0;i<n;i++)
            mp[arr[i]] = 1;
        for(int i = 1;i<n;i++)
        {
            auto it3 = mp.find(arr[i]);
            int cnt = 0;
            for(int j = 0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    auto it = mp.find(arr[i]/arr[j]);
                    auto it2 = mp.find(arr[j]);
                    if(it!=mp.end())
                    {
                        cnt = (cnt+ (it->second*it2->second)%mod)%mod;
                    }
                }
            }
            it3->second = (it3->second + cnt)%mod;
        }
        long long int sum = 0;
        for(auto it:mp)
            sum = (sum+it.second)%mod;
        return sum%mod;
    }
};