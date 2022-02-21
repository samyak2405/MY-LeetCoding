class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        int majority = 0,max = INT_MIN;
        for(auto it:mp)
        {
            if(it.second>max)
            {
                max = it.second;
                majority = it.first;
            }
        }
        return majority;
    }
};