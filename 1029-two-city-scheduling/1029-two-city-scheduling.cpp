class Solution {
public:
    
    static bool cmp(vector<int> &cost1,vector<int> &cost2)
    {
        return (cost1[0]-cost1[1])<(cost2[0]-cost2[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),cmp);
        int total = 0;
        
        for(int i = 0;i<costs.size();i++)
        {
            if(i<costs.size()/2)
                total+=costs[i][0];
            else
                total+=costs[i][1];
        }
        
        return total;
    }
};