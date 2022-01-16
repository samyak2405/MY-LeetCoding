class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> indexes;
        indexes.push_back(0);
        for(int i =0;i<seats.size();i++)
        {
            if(seats[i]==1)
                indexes.push_back(i);
        }
        int res = 0;
        indexes.push_back(seats.size()-1);
        // if(indexes.size()==3)
        // {
        //     return max(indexes[1]-indexes[0],indexes[2]-indexes[1]);
        // }
        // else
            for(int i = 2;i<indexes.size()-1;i++)
            {
                res = max((indexes[i]-indexes[i-1])/2,res);
            }
            res = max(indexes[1]-indexes[0],res);
            res = max(indexes[indexes.size()-1]-indexes[indexes.size()-2],res);
        return res;
    }
};