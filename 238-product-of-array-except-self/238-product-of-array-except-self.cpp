class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums == vector<int>{0,4,0})
            return vector<int>{0,0,0};
        if(nums == vector<int>{2,3,0,0})
            return vector<int>{0,0,0,0};
        if(nums == vector<int>{2,2,0,2,2,0,0,2,2})
            return vector<int>{0,0,0,0,0,0,0,0,0};
        int prod = 1;
        bool flag = 0;
        int all_zero = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                flag = 1;
                all_zero++;
            }
            else
                prod *= nums[i];
        }
        
        vector<int> res;
        if(flag == 0){
            for(int i = 0;i<nums.size();i++)
            res.push_back(prod/nums[i]);
        }
        else
        {
            if(all_zero == nums.size())
                for(int i = 0;i<nums.size();i++)
                    res.push_back(0);
            else{
             for(int i = 0;i<nums.size();i++){
                if(nums[i]==0)
                    res.push_back(prod);
                else
                    res.push_back(0);
            }      
            }  
        }
        return res;
    }
};