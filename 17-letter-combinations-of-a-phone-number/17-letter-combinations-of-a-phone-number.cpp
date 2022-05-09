class Solution {
public:
    
    void backtrack(int ind,string s,string tmp,vector<string> &res,map<char,vector<char>> &mp)
    {
        if(ind==s.length())
        {
            res.push_back(tmp);
            return;
        }
        for(auto it:mp[s[ind]])
        {
            tmp.push_back(it);
            backtrack(ind+1,s,tmp,res,mp);
            tmp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string s) {
         vector<string> res;
        if(!s.length())
            return res;
        map<char,vector<char>> mp;
        mp['2'] = vector<char>{'a','b','c'};
        mp['3'] = vector<char>{'d','e','f'};
        mp['4'] = vector<char>{'g','h','i'};
        mp['5'] = vector<char>{'j','k','l'};
        mp['6'] = vector<char>{'m','n','o'};
        mp['7'] = vector<char>{'p','q','r','s'};
        mp['8'] = vector<char>{'t','u','v'};
        mp['9'] = vector<char>{'w','x','y','z'};
        
        backtrack(0,s,"",res,mp);
        
        return res;
    }
};