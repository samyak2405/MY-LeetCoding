class Solution {
public:
    
    bool check(vector<int> &base,vector<int> &top)
    {
        if(base[0]>=top[0] and base[1]>=top[1] and base[2]>=top[2])
            return true;
        return false;
    }
    
    int f(int n,vector<vector<int>> &cuboids)
    {
        vector<int> next(n+1,0),current(n+1,0);
        for(int curr = n-1;curr>=0;curr--)
        {
            for(int prev = curr-1;prev>=-1;prev--)
            {
                int take = 0;
                int not_take = next[prev+1];
                if(prev==-1 or check(cuboids[curr],cuboids[prev]))
                    take = cuboids[curr][2] + next[curr+1];
                current[prev+1] = max(take,not_take);
            }
            next = current;
        }
        return next[0];
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        //sort all dimensions for every cuboids
        for(auto &it:cuboids)
            sort(it.begin(),it.end());
        sort(cuboids.begin(),cuboids.end());
        int n = cuboids.size();
        return f(n,cuboids);
    }
};