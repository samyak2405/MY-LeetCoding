class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        queue<int> q;
        for(auto it:nums)
            q.push(it);
        while(q.size()>1)
        {
            int sz = q.size();
            for(int i = 0;i<sz-1;i++)
            {
                int a = q.front();
                q.pop();
                int c = (a+q.front())%10;
                q.push(c);
            }
            q.pop();
        }
        return q.front();
    }
};