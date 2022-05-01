class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]!='#')
                s1.push(s[i]);
            else if(s[i]=='#' and s1.size()==0)
                continue;
            else
                s1.pop();
        }
        for(int i = 0;i<t.length();i++)
        {
            if(t[i]!='#')
                s2.push(t[i]);
            else if(t[i]=='#' and s2.size()==0)
                continue;
            else
                s2.pop();
        }
        return s1==s2;
    }
};