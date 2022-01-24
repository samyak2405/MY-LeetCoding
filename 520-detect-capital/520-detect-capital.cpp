class Solution {
public:
    bool detectCapitalUse(string word) {
        int up = 0,low =0;
        for(int i = 0;i<word.size();i++)
        {
            if(word[i]>='A' and word[i]<='Z')
                up++;
            else
                low++;
        }
        if((word[0]>='a' and word[0]<='z')and(up>=1) )
            return false;
        if((up>=1 and low==0) or (up<=1 and low!=0))
            return true;
        return false;
    }
};