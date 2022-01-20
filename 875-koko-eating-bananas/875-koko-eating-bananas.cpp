class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int _max = 1000000000;
        int k = 1;
        int ans = 0;
        vector<int> v1 = piles;
        while(k<=_max)
        {
            int mid = k + (_max-k)/2;
            int tot = 0;
            for(auto it:v1)
            {
                if(mid>it)
                    tot++;
                else{
                    tot+=it/mid;
                    if(it%mid!=0)
                        tot++;
                }
            }
            if(tot<=h)
            {
                ans = mid;
                _max = mid-1;
            }
            else
            {
                k = mid+1;
            }
            v1 = piles;
        }
        return ans;
    }
};