class Solution {
public:
    int t[301][301];
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m =matrix[0].size();
        
        memset(t, 0, sizeof(t));
        
        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==n-1 && matrix[i][j]=='1')
                    t[i][j] = 1;
                if(j==m-1 && matrix[i][j]=='1')
                    t[i][j] = 1;
            }
        }
        
        
        for(int i = n-2; i>=0; i--){
            for(int j =m-2 ; j>=0; j--){
                if(matrix[i][j]=='1'){
                    t[i][j] = 1+min(t[i+1][j], min(t[i][j+1], t[i+1][j+1]));
                }

            }
        }
        
        int mx = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0;j<m; j++)
                mx = max(mx, t[i][j]);
        }
       return pow(mx, 2); 
    }
};