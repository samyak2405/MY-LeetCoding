class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> indexes;
        
        indexes.push_back(0);
        
        for(int i =0;i<seats.size();i++)
            if(seats[i]==1)
                indexes.push_back(i);
        indexes.push_back(seats.size()-1);
        
        int res = 0;
        int n = indexes.size();
        
        for(int i = 2;i<n-1;i++)
        {
            res = max((indexes[i]-indexes[i-1])/2,res);
        }
        res = max(indexes[1]-indexes[0],res);
        res = max(indexes[n-1]-indexes[n-2],res);
        return res;
    }
};