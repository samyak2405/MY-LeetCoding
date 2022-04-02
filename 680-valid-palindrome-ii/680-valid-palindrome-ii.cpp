class Solution {
public:
    
    bool isPallindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return isPallindrome(s,i+1,j) or isPallindrome(s,i,j-1);
            }
            i++;
            j--;
        }
        return true;
    }
};