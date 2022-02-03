class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i = 1;i<=n;i++)
        {
            nums.push_back(i);
        }
        vector<vector<int>> res;
        
        for(int num = 0;num<pow(2,n);num++)
        {
            vector<int> tmp;
            for(int j = 0;j<nums.size();j++)
            {
                if(num&(1<<j))
                    tmp.push_back(nums[j]);
            }
            if(tmp.size()==k)
                res.push_back(tmp);
        }
        
        return res;
    }
};