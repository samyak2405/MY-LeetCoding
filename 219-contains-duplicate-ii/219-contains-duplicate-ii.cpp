class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k<=0)
            return false;
        if(k>=nums.size())
            k = nums.size()-1;
        unordered_set<int> s1;
        for(int i = 0;i<nums.size();i++)
        {
            if(i>k)
                s1.erase(nums[i-k-1]);
            if(s1.find(nums[i])!=s1.end())
                return true;
            s1.insert(nums[i]);
                
        }
        return false;
    }
};