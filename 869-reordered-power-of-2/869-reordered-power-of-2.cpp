class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n==1)
            return true;
        string res = "";
        while(n>0)
        {
            res+=to_string(n%10);
            n/=10;
        }
        sort(res.begin(),res.end());
        do{
            if(res[0]!='0')
            {
                int x = stoi(res);
                if(ceil(log2(x))==floor(log2(x)))
                   return true;
            }
        }while(next_permutation(res.begin(),res.end()));
        return false;
    }
};