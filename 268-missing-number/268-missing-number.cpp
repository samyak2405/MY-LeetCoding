class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int _xor = 0;
        
        for(int i = 0;i<nums.size();i++)
            _xor^=nums[i]^i;
        
        _xor^=nums.size();
        
        return _xor;
    }
};