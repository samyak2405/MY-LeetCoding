class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        stack<char> s1;
        int i = 0;
        while(i<s.length())
        {
            if(s1.empty() or (!s1.empty() and s1.top()!=s[i]))
            {
                s1.push(s[i]);
            }
            else if(s1.top()==s[i])
            {
                s1.pop();
            }
            i++;
        }
        
        while(!s1.empty())
        {
            res+=s1.top();
            s1.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};