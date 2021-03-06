class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, down = n-1;
        int left = 0, right= m-1;
        int dir = 0;
        vector<int>v;
       while(top<=down && left<=right){
           if(dir==0){
               for(int i=left; i<=right; i++){
                   v.push_back(matrix[top][i]);
               }
               top++;
           }
           else if(dir==1){
               for(int i=top; i<=down; i++){
                   v.push_back(matrix[i][right]);
               }
               right--;
           }
           else if(dir==2){
               for(int i=right; i>=left; i--){
                   v.push_back(matrix[down][i]);
               }
               down--;
           }
           else{
               for(int i=down; i>=top; i--){
                   v.push_back(matrix[i][left]);
               }
               left++;
           }
           dir = (dir+1)%4;
       }
        return v;
    }
};