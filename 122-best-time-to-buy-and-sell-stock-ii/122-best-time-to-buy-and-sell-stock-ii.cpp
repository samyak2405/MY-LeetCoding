class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currbuy,currnotbuy,aheadbuy = 0,aheadnotbuy = 0;
        int n = prices.size();
        for(int ind = n-1;ind>=0;ind--)
        {
            currnotbuy = max(prices[ind]+aheadbuy,aheadnotbuy);
            currbuy = max(-prices[ind]+aheadnotbuy,aheadbuy);
            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
        return currbuy;
    }
};