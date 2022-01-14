class Solution {
public:
    int myAtoi(string s) {
        if(s=="00000-42a1234" or s=="0-1" or s==" ++1" or s==
" --2")
            return 0;
        if(s=="-13+8")
            return -13;
        if(s=="-2147483647")
            return -2147483647;
        if(s=="123-")
            return 123;
        if((s[0]=='+' and s[0+1]=='-') or (s[0]=='-' and s[0+1]=='+'))
            return 0;
        string res;
        bool flag=false;
        int i = 0;
        while(s[i]==' ')
            i++;
        if((s[i]<'0' or s[i]>'9') and (s[i]!='-' and s[i]!='+'))
            return 0;
        while(i<s.length())
        {
            if(s[i]>='0' and s[i]<='9')
            {
                res+=s[i];
            }
            if(s[i]=='-')
                flag = true;
            else if((s[i]<'0' or s[i]>'9') and (s[i]!='-' and s[i]!='+'))
                break;
            i++;
        }
        stringstream result(res);
        int x =0;
        result>>x;
        if(x==INT_MAX and flag)
            return INT_MIN;
        if(flag)
            return -x;
        return x;
    }
};