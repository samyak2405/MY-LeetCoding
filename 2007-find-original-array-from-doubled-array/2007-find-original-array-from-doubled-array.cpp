class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        vector<int> res;
        if(arr.size()%2)
            return res;
        int zero = 0;
        
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i:arr)
        {
            if(i==0)
                zero++;
            mp[i]++;
        }
        if(zero%2)
            return res;
        // cout<<mp[0];
        sort(arr.begin(),arr.end());
        for(int i = 0;i<n;i++)
        {
            if(mp.find(arr[i]*2)!=mp.end() and mp[arr[i]]!=0)
            {
                
                // cout<<mp[arr[i]]<<" "<<mp[arr[i]*2]<<"::";
                res.push_back(arr[i]);
                mp[arr[i]]--;
                if(!mp[arr[i]])
                    mp.erase(arr[i]);
                
                mp[arr[i]*2]--;
                if(!mp[arr[i]*2])
                    mp.erase(arr[i]*2);
                // cout<<mp[arr[i]]<<" "<<mp[arr[i]*2]<<endl;
            }
        }
        if(res.size()!=arr.size()/2)
            return vector<int>{};
        return res;
    }
};