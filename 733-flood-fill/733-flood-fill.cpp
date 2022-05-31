class Solution {
public:
    
    void dfs(int sr, int sc, vector<vector<int>>& image, int newColor, int oldColor){
        if(sr >= image.size() || sr <0 || sc >= image[0].size() || sc<0 || image[sr][sc]!=oldColor)
            return;
        image[sr][sc] = newColor;
        
        dfs(sr+1, sc, image, newColor, oldColor);
        dfs(sr-1, sc, image, newColor, oldColor);
        dfs(sr, sc+1, image, newColor, oldColor);
        dfs(sr, sc-1, image, newColor, oldColor);        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int n = image.size(); int m = image[0].size();
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == sr && j == sc && image[i][j]!=newColor){
                    int oldColor = image[i][j];
                    dfs(i, j, image, newColor, oldColor);
                }
            }
        }
        return image;
    }
};