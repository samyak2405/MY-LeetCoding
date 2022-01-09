class Solution {
public:
    bool isRobotBounded(string ins) {
        int x = 0, y = 0, i =0;
        vector<vector<int>> d = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(int j = 0;j<ins.size();j++)
        {
            if(ins[j]=='G')
            {
                x+=d[i][0];
                y+=d[i][1];
            }
            else if(ins[j] == 'R')
            {
                i = (i+1)%4;
            }
            else if(ins[j] == 'L')
            {
                i = (i+3)%4;
            }
        }
        if(x==0 and y==0 or i>0)
            return true;
        return false;
    }
};