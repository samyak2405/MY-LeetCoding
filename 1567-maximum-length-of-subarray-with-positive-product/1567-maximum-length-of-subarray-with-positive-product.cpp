class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        for(int i = 0;i<n;)
        {
            int s = i;
            while(s<n and nums[s]==0)
                s++;
            int e = s;
            int cnt = 0;
            int sn = -1,en = -1;
            while(e<n and nums[e]!=0)
            {
                if(nums[e]<0)
                {
                    cnt++;
                    if(sn==-1)
                        sn = e;
                    en = e;
                }
                e++;
            }
            if(!(cnt%2))
                res = max(res,e-s);
            else
            {
                if(sn!=-1)
                    res = max(res,e-sn-1);
                if(en!=-1)
                    res = max(res,en-s);
            }
            i = e+1;
        }
        return res;
    }
};