class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,n*n));
        int cnt = n*n;
        int tmp = 1;
        
        int top = 0,down = n-1,left = 0,right = n-1;
        int dir = 0;
        while(tmp!=cnt)
        {
            if(dir == 0)
            {
                for(int i = left;i<=right;i++)
                {
                    res[top][i] = tmp;
                    tmp++;
                }
                top++;
                dir = 1;
            }
            else if(dir == 1)
            {
                for(int i = top;i<=down;i++)
                {
                    res[i][right] = tmp;
                    tmp++;
                }
                right--;
                dir =2;
            }
            else if(dir == 2)
            {
                for(int i = right;i>=left;i--)
                {
                    res[down][i] = tmp;
                    tmp++;
                }
                down--;
                dir =3;
            }
            else if(dir == 3)
            {
                for(int i = down;i>=top;i--)
                {
                    res[i][left] = tmp;
                    tmp++;
                }
                left++;
                dir =0;
            }
        }
        
        return res;
    }
};