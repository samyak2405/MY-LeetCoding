class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = 0;
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
            if(nums[i]==0)
                nums[i]=-1;
        unordered_map<int,int> mp;
        for(int i = 0 ;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==0)
                len = max(len,i+1);
            if(mp.find(sum)!=mp.end())
                len = max(len,i-mp[sum]);
            if(mp.find(sum)==mp.end())
                mp[sum] = i;
        }
        return len;
    }
};