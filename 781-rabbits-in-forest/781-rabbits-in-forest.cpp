class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for(auto it:answers)
            mp[it+1]++;
        int sum = 0;
        
        for(auto it:mp)
        {
            while(it.second>it.first)
            {
                sum+=it.first;
                it.second-=it.first;
            }
            if(it.second>0)
            {
                sum+=it.first;
                it.second=0;
            }
        }
        
        return sum;
    }
};