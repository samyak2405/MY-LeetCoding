class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
 
        int i;
        for(i = 0;i<n;i++)
            if(matrix[i][m-1]>=target)
                break;
        if(i==n)
            return false;
        if(i<n and matrix[i][m-1]==target)
            return true;
        int low = 0,high = m-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(matrix[i][mid]==target)
                return true;
            else if(matrix[i][mid]>target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    }
};