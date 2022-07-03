class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size()),pos,neg;
        for(int  i =0;i<nums.size();i++)
        {
            if(nums[i]>=0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        int k = 0,j = 0;
        for(int i = 0;i<nums.size();i+=2)
        {
            res[i] = pos[k];
            k++;
            res[i+1] = neg[j];
            j++;
        }
        return res;
    }
};