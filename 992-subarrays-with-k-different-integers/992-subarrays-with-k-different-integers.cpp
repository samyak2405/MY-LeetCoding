class Solution {
public:
    
    int atmost(vector<int> &nums,int k)
    {
        int res = 0;
        unordered_map<int,int> mp;
        int j = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(!mp[nums[i]])
                k--;
            mp[nums[i]]++;
            while(k<0)
            {
                mp[nums[j]]--;
                if(!mp[nums[j]])
                    k++;
                j++;
            }
            res+=i-j+1;
        }
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};