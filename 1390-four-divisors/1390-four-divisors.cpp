class Solution {
public:
    
    bool cntDiv(int n,int &sum)
    {
        int cnt= 0;
        for(int i = 1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                sum +=i;
                cnt++;
                if((n/i)!=i)
                {
                    sum+=(n/i);
                    cnt++;
                }
            }
        }
        return cnt==4;
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(int i = 0;i<nums.size();i++)
        {
            int sum = 0;
            if(cntDiv(nums[i],sum))
                total += sum;
        }
        return total;
    }
};