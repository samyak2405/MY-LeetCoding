class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i<n;i++)
        {
            int j = 0,k = n-1;
            while(j<k)
                swap(matrix[j++][i],matrix[k--][i]);
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int cnt = 4;
        while(cnt--)
        {
            if(mat==target)
                return true;
            rotate(mat);
        }
        return false;
    }
};