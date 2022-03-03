class Solution {
public:
    
    bool isAP(vector<int> &v1)
    {
        sort(v1.begin(),v1.end());
        int d = v1[1] - v1[0];
        for(int i = 1;i<v1.size();i++)
            if(i+1<v1.size() and (v1[i+1]-v1[i]!=d))
                return false;
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        
        for(int i = 0;i<l.size();i++)
        {
            vector<int> tmp;
            for(int j = l[i];j<=r[i];j++)
                tmp.push_back(nums[j]);
            res.push_back(isAP(tmp));
        }
        
        return res;
    } 
};