class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int r = matrix.size(),c = matrix[0].size();
        int top = 0,down = r-1,left = 0,right = c-1;
        int dir = 0;
        int cnt = r*c;
        
        while(cnt)
        {
            if(dir == 0)
            {
                for(int i = left;i<=right;i++)
                {
                    res.push_back(matrix[top][i]);
                    cnt--;
                }
                top++;
                dir = 1;
            }
            else if(dir == 1)
            {
                for(int i = top;i<=down;i++)
                {
                    res.push_back(matrix[i][right]);
                    cnt--;
                }
                right--;
                dir = 2;
            }
            else if(dir == 2)
            {
                for(int i = right;i>=left;i--)
                {
                    res.push_back(matrix[down][i]);
                    cnt--;
                }
                down--;
                dir =3;
            }
            else if(dir == 3)
            {
                for(int i = down;i>=top;i--)
                {
                    res.push_back(matrix[i][left]);
                    cnt--;
                }
                left++;
                dir = 0;
            }
        }
        
        return res;
    }
};