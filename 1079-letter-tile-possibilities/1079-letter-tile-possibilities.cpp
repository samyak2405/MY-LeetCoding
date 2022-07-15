class Solution {
public:
    
    void subsequences(vector<string> &tmp,string tiles,int ind,string t)
    {
        if(ind==tiles.size())
        {
            if(t.size())
                tmp.push_back(t);
            return;
        }
        t.push_back(tiles[ind]);
        subsequences(tmp,tiles,ind+1,t);
        t.pop_back();
        subsequences(tmp,tiles,ind+1,t);
    }
    
    void permute(string s,unordered_set<string> &s1,int l,int r)
    {
        if(l>r)
        {
            s1.insert(s);
            return;
        }
        for(int i = l;i<=r;i++)
        {
            swap(s[i],s[l]);
            permute(s,s1,l+1,r);
            swap(s[i],s[l]);
        }
    }
    
    int numTilePossibilities(string tiles) {
        vector<string> combo;
        subsequences(combo,tiles,0,"");
        unordered_set<string> s1;
        for(auto it:combo)
            permute(it,s1,0,it.size()-1);
        return s1.size();
    }
};