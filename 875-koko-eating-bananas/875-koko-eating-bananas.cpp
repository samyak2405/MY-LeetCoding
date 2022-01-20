class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = 1;
        int _max = INT_MAX;
        for(auto it:piles)
            _max = max(_max,it);
        int ans = 0;
        vector<int> v1;
        while(k<=_max){
            int mid = k+(_max-k)/2;
            int tot_h = 0;
            for(auto it:v1){
                if(mid>it)
                    tot_h++;
                else
                {
                    tot_h += it/mid;
                    if(it%mid!=0)
                        tot_h++;
                }
            }
            if(tot_h<=h)
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