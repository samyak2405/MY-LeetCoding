class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = -1e8;
        int i = 0;
        int j = 0;
        int n = cardPoints.size();
        int sum = 0,tot_sum = 0;
        for(auto it:cardPoints)
            tot_sum+=it;
        while(j<n)
        {
            sum+=cardPoints[j];
            if(j-i+1==n-k)
            {
                ans = max(ans,tot_sum-sum);
                sum-=cardPoints[i];
                i++;
            }
            j++;
        }
        return ans==-1e8?tot_sum:ans;
    }
};