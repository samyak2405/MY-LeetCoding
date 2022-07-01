class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        
        int sum = 0;
        int i = 0;
        while(truckSize>0 and i<boxTypes.size())
        {
            if(truckSize>boxTypes[i][0])
            {
                
                sum+=(boxTypes[i][0]*boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
                i++;
            }
            else
            {
                sum+=(truckSize*boxTypes[i][1]);
                truckSize = 0;
            }
        }
        return sum;
    }
};