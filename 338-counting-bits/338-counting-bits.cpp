class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        
        for(int i = 0;i<=n;i++)
        {
            int cnt = 0;
            int k = i;
            while(k)
            {
                if(k&1)
                    cnt++;
                k>>=1;
            }
            res.push_back(cnt);
        }
        
        return res;
    }
};