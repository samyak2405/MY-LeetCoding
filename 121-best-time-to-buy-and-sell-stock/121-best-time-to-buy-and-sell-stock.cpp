class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprice = 0;
        
        for(int i = 0;i<prices.size();i++)
        {
            if(minprice>prices[i])
                minprice = prices[i];
            if(prices[i]-minprice>maxprice)
                maxprice = prices[i]-minprice;
        }
        
        return maxprice;
    }
};