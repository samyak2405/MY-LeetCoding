class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1,c = 0;
        string res;
        while(i>=0 or j>=0 or c==1)
        {
            c+=(i>=0)?a[i--]-'0':0;
            c+=(j>=0)?b[j--]-'0':0;
            res = char(c%2+'0')+res;
            c/=2;
        }
        
        return res;
    }
};