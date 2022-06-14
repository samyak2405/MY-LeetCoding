class Solution {
public:
    int find(vector<int> &parent,int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x] = find(parent,parent[x]);
    }
    
    bool _union(vector<int> &parent,int x,int y)
    {
        int x_rep = find(parent,x);
        int y_rep = find(parent,y);
        if(x_rep==y_rep)
            return false;
        parent[y_rep] =x_rep;
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int> parent(stones.size());
        for(int i = 0;i<stones.size();i++)
            parent[i] = i;
        int stone = 0;
        for(int i = 0;i<stones.size();i++)
        {
            for(int j = i+1;j<stones.size();j++)
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
                    if(_union(parent,i,j))
                        stone++;
        }
        return stone;
    }
};