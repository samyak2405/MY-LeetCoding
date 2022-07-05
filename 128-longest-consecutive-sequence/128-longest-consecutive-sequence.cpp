class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s1;
        for(auto it:nums)
            s1.insert(it);
        int res = 0;
        for(int i = 0;i<nums.size();i++)
        {
            int cnt = 0;
            int start = nums[i];
            if(s1.find(start-1)!=s1.end())
                continue;
            else
            {
                while(s1.find(start)!=s1.end())
                {
                    cnt++;
                    start++;
                }   
            }
            
            res = max(cnt,res);
        }
        return res;
    }
};