class Solution {
public:
    
    int solve(int cap,vector<int> &arr)
    {
        int sum = 0;
        int cnt = 0;
        for(int a :arr)
        {
            if(a>cap)
                return INT_MAX;
            if(sum+a<=cap)
                sum+=a;
            else
            {
                sum = a;
                cnt++;
            }
        }
        return cnt;
    }
    
    int shipWithinDays(vector<int>& arr, int days) {
        int low = 1;
        int high = 1e9;
        
        while(low<high)
        {
            int mid = low+(high-low)/2;
            int d = solve(mid,arr);
            if(d<days)
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};