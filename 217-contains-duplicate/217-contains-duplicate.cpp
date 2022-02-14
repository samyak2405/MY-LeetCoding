class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s1;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(s1.find(nums[i])!=s1.end())
                return true;
            else
                s1.insert(nums[i]);
        }
        return false;
    }
};