/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bsrev(MountainArray &mountainArr,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            if(mountainArr.get(mid)>target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
    int bs(MountainArray &mountainArr,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            if(mountainArr.get(mid)<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if(mountainArr.length()<3)
            return -1;
        int low = 0;
        int high = mountainArr.length()-1;
        while(low<high)
        {
            int mid = low+(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
                low = mid+1;
            else
                high = mid;
        }
        high = mountainArr.length()-1;
        int val = bs(mountainArr,0,low,target);
        if(val!=-1)
            return val;
        
        return bsrev(mountainArr,low+1,high,target);
    }
};