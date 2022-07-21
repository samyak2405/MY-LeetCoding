class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int remains = 0;
        int res = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        while(j<n)
        {
            if(mp[nums[j]]==0)
                remains++;
            mp[nums[j]]++;
            while(remains>2)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    remains--;
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};