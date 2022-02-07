class Solution {
public:
    char findTheDifference(string s, string t) {
        char _xor = 0;
        for(auto it:s)
            _xor^=it;
        for(auto it:t)
            _xor^=it;
        
        return _xor;
    }
};