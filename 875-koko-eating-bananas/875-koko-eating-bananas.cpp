class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int _max = 1000000000;
        int k = 1;
        while(k<_max)
        {
            int mid = k + (_max-k)/2;
            int tot = 0;
            for(auto it:piles)
            {
                tot += (it+mid-1)/mid;
            }
            if(tot>h)
            {
                k = mid+1;
            }
            else
            {
                _max = mid;
            }
        }
        return _max;
    }
};