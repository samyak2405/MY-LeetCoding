class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = queries.size();
        int sum = 0;
        for(int i:nums)
            if(i%2==0)
                sum+=i;
        for(int i = 0;i<n;i++)
        {
            int val = queries[i][0];
            int index = queries[i][1];
            int tmp = nums[index];
            nums[index] = nums[index]+val;
            if(tmp%2==0 and nums[index]%2==0)
                sum+=val;
            else if(tmp%2==0 and nums[index]%2)
                sum-=tmp;
            else if(tmp%2 and nums[index]%2==0)
                sum+=nums[index];
            res.push_back(sum);
            
        }
        return res;
    }
};