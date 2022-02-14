class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int _xor = 0;
        for(auto it:nums)
            _xor^=it;
        return _xor;
    }
};