class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        sort(arr2.begin(),arr2.end());
        for(int i = 0;i<arr1.size();i++)
        {
            bool flag = true;
            int low = 0,high = arr2.size()-1;
            while(low<=high)
            {
                int mid = low+(high-low)/2;
                if(abs(arr1[i]-arr2[mid])<=d)
                {
                    flag = false;
                    break;
                }
                if(arr1[i]<arr2[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            if(flag)
                cnt++;
        }
        return cnt;
    }
};