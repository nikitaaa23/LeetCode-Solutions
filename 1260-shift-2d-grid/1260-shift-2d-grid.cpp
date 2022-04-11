class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int size = n*m;
         vector<vector<int>>mat(n, vector<int>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0;j<m; j++){
                int f = i*m + j;
                int nf = (f+k)%size;
                int nr = nf/m;
                int nc = nf%m;
                mat[nr][nc] = grid[i][j];
            }
        }
        return mat;
    }
};