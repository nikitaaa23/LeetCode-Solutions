class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
//         queue<pair<int, int>>q;
        
//         for(int i = 0; i<matrix.size(); i++){
//             for(int j = 0; j<matrix[0].size(); j++){
//                 if(matrix[i][j]==0)
//                     q.push({i, j});
//             }
//         }
        
//         while(!q.empty()){
//             int x = q.front().first;
//             int y = q.front().second;
//             q.pop();
            
//             for(int i = 0; i<matrix[0].size(); i++){
//                 matrix[x][i]= 0;
//             }
//             for(int i = 0; i<matrix.size(); i++){
//                 matrix[i][y]= 0;
//             }
//         }
        bool flag = false;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i<n; i++){
            if(matrix[i][0] == 0){
                flag = true;
            }
            for(int j = 1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
         for(int i = 1; i<n; i++){
             for(int j = 1; j<m; j++){
                 if(matrix[i][0] == 0 || matrix[0][j] == 0){
                     matrix[i][j] = 0;
                 }
             }
         }
        
        if(matrix[0][0]==0){
            for(int j = 0; j<m; j++){
                matrix[0][j] = 0;
            }
        }
        
        if(flag){
            for(int i = 0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
        
    }
};