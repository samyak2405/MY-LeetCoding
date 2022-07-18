class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        if(piles.size()<1)
            return 0;
        if(piles.size()==2)
            return piles[0];
        int n = piles.size()/3;
        int i = piles.size()-2;
        
        int sum = 0;
        while(i>=0 and n--)
        {
            sum+=piles[i];
            i-=2;
        }
        return sum;
    }
};