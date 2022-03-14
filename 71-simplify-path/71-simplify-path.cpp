class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string res,tmp;
        vector<string> s1;
        while(getline(ss,tmp,'/'))
        {
            if(tmp == "" or tmp==".")
                continue;
            else if(tmp ==".." and !s1.empty())
                s1.pop_back();
            else if(tmp!="..")
                s1.push_back(tmp);
        }
        for(auto it:s1)
            res+="/"+it;
        return res.empty()?"/":res;
        
    }
};