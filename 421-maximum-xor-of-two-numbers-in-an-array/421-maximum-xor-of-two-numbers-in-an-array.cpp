class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi = 0,mask = 0;
        
        for(int i = 30;i>=0;i--)
        {
            set<int> s1;
            
            mask |= (1<<i);
            
            for(auto it:nums)
                s1.insert(it&mask);
            
            int newmax = maxi |(1<<i);
            
            for(auto it:s1)
            {
                if(s1.count(it^newmax))
                {
                    maxi = newmax;
                    break;
                }
            }
        }
        return maxi;
    }
};