class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int i = 0;i<nums.size();i++)
            mp[nums[i]]++;
        int cnt = 0;
        for(auto it:mp)
        {
            if((k>0 and mp.find(it.first+k)!=mp.end()) or (k==0 and it.second>1))
                cnt++;
        }
        return cnt;
    }
};