class Solution {
public:
    int fillCups(vector<int>& amounts) {
        int mx = INT_MIN;
        int sum = 0;
        for(int i = 0;i<amounts.size();i++)
        {
            mx = max(mx,amounts[i]);
            sum+=amounts[i];
        }
        return max(mx,(sum+1)/2);
    }
};