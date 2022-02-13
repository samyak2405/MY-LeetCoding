class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int _xor = 0;
        
        for(int i = 0;i<nums.size();i++)
            _xor^=nums[i];
        
        for(int i = 0;i<=nums.size();i++)
            _xor^=i;
        
        return _xor;
    }
};