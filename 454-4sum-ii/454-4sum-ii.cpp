class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt = 0;
        unordered_map<int,int> mp;
        for(auto it:nums1)
            for(auto itr:nums2)
                mp[it+itr]++;
        
        for(auto it:nums3)
            for(auto itr:nums4)
                if(mp.count(-(it+itr)))
                    cnt+=mp[-(it+itr)];
        
        return cnt;
    }
};