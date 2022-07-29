class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curr_color=image[sr][sc];
        dfs(image, sr, sc, curr_color, color);
        return image;
    }
    
    void dfs(vector<vector<int>>&image, int sr, int sc, int color, int newColor){
         if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=color || image[sr][sc]==newColor)
            return;
        
        image[sr][sc]=newColor;
        dfs(image, sr-1, sc, color, newColor);
        dfs(image, sr, sc-1, color, newColor);
        dfs(image, sr, sc+1, color, newColor);
        dfs(image, sr+1, sc, color, newColor);
    }
};