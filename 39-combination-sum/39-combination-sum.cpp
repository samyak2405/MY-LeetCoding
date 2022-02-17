class Solution {
public:
    typedef vector<vector<int>> vvi;
    typedef vector<int> vi;
    
    void combine(vi &candidates,int target,int index,vvi &res,vi &tmp)
    {
        if(target<0)
            return;
        if(index==candidates.size())
        {
            if(!target)
                res.push_back(tmp);
            return;
        }
        if(candidates[index]<=target)
        {
            tmp.push_back(candidates[index]);
            combine(candidates,target-candidates[index],index,res,tmp);
            tmp.pop_back();
        }
        combine(candidates,target,index+1,res,tmp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vvi res;
        vi tmp;
        combine(candidates,target,0,res,tmp);
        return res;
    }
};