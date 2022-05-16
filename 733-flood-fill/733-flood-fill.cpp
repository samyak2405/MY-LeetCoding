class Solution {
public:
    
    void dfs(vector<vector<int>> &image,int i,int j,int newColor,int currColor)
    {
        if(i<0 or j<0 or i>=image.size() or j>=image[0].size() or image[i][j]!=currColor)
            return;
        image[i][j] = newColor;
        dfs(image,i+1,j,newColor,currColor);
        dfs(image,i-1,j,newColor,currColor);
        dfs(image,i,j+1,newColor,currColor);
        dfs(image,i,j-1,newColor,currColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor)
            dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};