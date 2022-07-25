class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt = 0,rank = 0;
        for(int i = 0;i<nums.size();i++)
        {
            cnt+=(target==nums[i]);
            if(nums[i]<target)
                rank++;
        }
        vector<int> res;
        while(cnt--)
            res.push_back(rank++);
        return res;
    }
};