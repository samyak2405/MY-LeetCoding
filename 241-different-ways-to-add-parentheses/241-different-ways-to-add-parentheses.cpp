class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        for(int i = 0;i<exp.length();i++)
        {
            char c = exp[i];
            if(c=='-' or c=='+' or c=='*')
            {
                string a = exp.substr(0,i);
                string b = exp.substr(i+1,exp.length());
                vector<int> sa = diffWaysToCompute(a);
                vector<int> sb = diffWaysToCompute(b);
                for(int i :sa)
                {
                    for(int j : sb)
                    {
                        if(c=='-')
                            res.push_back(i-j);
                        else if(c=='+')
                            res.push_back(i+j);
                        else
                            res.push_back(i*j);
                    }
                }
            }
        }
        if(!res.size())
            res.push_back(stoi(exp));
        return res;
    }
};