class Solution {
public:
    int scoreOfParentheses(string s) {
        int scr = 0;
        stack<int> s1;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                s1.push(scr);
                scr = 0;
            }
            else
            {
                scr  = s1.top() + max(scr*2,1);
                s1.pop();
            }
        }
        return scr;
    }
};