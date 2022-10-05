class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int x = nums1.size();
        int y = nums2.size();
        int low = 0;
        int high = x;
        while(low<=high)
        {
            int partx = (low+high)/2;
            int party = ((x+y+1)/2)-partx;
            
            int x2 = partx==0?INT_MIN:nums1[partx-1];
            int x3 = partx==x?INT_MAX:nums1[partx];
            int y5 = party==0?INT_MIN:nums2[party-1];
            int y6 = party==y?INT_MAX:nums2[party];
            
            if(x2<=y6 and y5<=x3)
            {
                if((x+y)%2==0)
                {
                    int a = max(x2,y5);
                    int b = min(x3,y6);
                    return (double)(a+b)/2.0;
                }
                else
                {
                    return max(x2,y5);
                }
            }
            else if(x2>y6)
                high = partx-1;
            else
                low = partx+1;
            
        }
        return 0;
    }
};