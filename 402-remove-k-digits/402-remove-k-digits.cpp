class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length())
            return "0";
        if(k==0)
            return num;
        stack<char> s1;
        int i = 0;
        while(i<num.length() and k)
        {
            if(!s1.empty() and s1.top()>num[i])
            {
                while(!s1.empty() and s1.top()>num[i] and k)
                {
                    s1.pop();
                    k--;
                }
                if(k==0)
                    break;
            }
            s1.push(num[i]);
            i++;
        }
        if(k)
        {
            while(!s1.empty() and k)
            {
                s1.pop();
                k--;
            }
        }
        string res;
        while(!s1.empty())
        {
            res+=s1.top();
            s1.pop();
        }
        reverse(res.begin(),res.end());
        while(i<num.length())
            res+=num[i++];
        string res1;
        i = 0;
        while(res[i]=='0')
            i++;
        res1.append(res.substr(i,res.length()));
        if(!res1.size())
            return "0";
        return res1;
    }
};