class NumMatrix {
    vector<vector<int>> mat,pre;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        vector<int> tmp(matrix[0].size()+1,0);
        for(int i = 0;i<matrix.size()+1;i++)
            pre.push_back(tmp);
        prefix();
    }
    
    void prefix()
    {
        for(int i =  1;i<pre.size();i++)
        {
            for(int j = 1;j<pre[0].size();j++)
            {
                pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+mat[i-1][j-1];
            }
        }
        // for(int i =  0;i<pre.size();i++)
        // {
        //     for(int j = 0;j<pre[0].size();j++)
        //     {
        //         cout<<pre[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
    
    
    int sumRegion(int a, int b, int c, int d) {
        return pre[c+1][d+1] - pre[a][d+1]-pre[c+1][b]+pre[a][b];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */