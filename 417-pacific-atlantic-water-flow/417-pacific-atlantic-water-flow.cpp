class Solution {
public:
    int dir[4][2] = {{0, 1}, {1, 0},  {-1, 0}, {0, -1}};
   void dfs(int i, int j, vector<vector<bool>>&vis, int ht, int r, int c, vector<vector<int>>& heights){
       if(i<0 || i>=r || j>=c || j<0 || vis[i][j] || ht > heights[i][j])
           return;
       vis[i][j]=true;
       
       dfs(i+1, j, vis, heights[i][j], r, c, heights);
       dfs(i, j+1, vis, heights[i][j], r, c, heights);
       dfs(i, j-1, vis, heights[i][j], r, c, heights);
       dfs(i-1, j, vis, heights[i][j], r, c, heights);
   }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>v;
        
        if(heights.size()==0 || heights[0].size()==0)
            return v;
        
        int r = heights.size();
        int c= heights[0].size();
        vector<vector<bool>>pacific(r, vector<bool>(c, false));
        vector<vector<bool>>atlantic(r, vector<bool>(c, false));
        
        for(int i = 0; i<r; i++){
            dfs(i, 0, pacific, heights[i][0], r, c, heights);
            dfs(i, c-1, atlantic, heights[i][c-1], r, c, heights);
        }
        
        for(int i = 0; i<c; i++){
            dfs(0, i, pacific, heights[0][i], r, c, heights);
            dfs(r-1, i, atlantic, heights[r-1][i], r, c, heights);
        }
        
        for(int i =0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(pacific[i][j] && atlantic[i][j])
                    v.push_back({i, j});
            }
        }
        return v;
    }
};