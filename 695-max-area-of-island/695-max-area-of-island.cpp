class Solution {
public:
    
     int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i < 0  || j<0 || i>=n || j>=m || grid[i][j] == 0){
            return 0;
        }
        grid[i][j]=0;
        int count = 1;
        for(int k =0; k<4; k++){
            int px = i + row[k];
            int py = j + col[k];
            
            if(px >=0 && px<n && py >=0 && py <m && grid[px][py]==1){
                count+=dfs(px, py, n, m, grid);
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    mx = max(mx, dfs(i, j, n, m, grid));
                }
            }
        }
        return mx;
    }
};