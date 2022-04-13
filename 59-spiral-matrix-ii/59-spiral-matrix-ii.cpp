class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>A(n, vector<int>(n));
    int num = 1;
    int dir = 0;
    int l = 0, r = n-1, t = 0, d = n-1;

    while(l<=r && t<=d){
        
        if(dir == 0){
            for(int i= l; i<=r; i++){
                
                A[t][i] = num++;
            }
            t++;
        }
        else if(dir == 1){
            for(int i= t; i<=d; i++){
                A[i][r] = num++;
            }
            r--;
        }
        else if(dir == 2){
            for(int i= r; i>=l; i--){
                A[d][i] = num++;
            }
            d--;
        }
        else if(dir == 3){
            for(int i= d; i>=t; i--){
                A[i][l] = num++;
            }
            l++;
        }

        dir = (dir+1)%4;
    } 
    return A;
    }
};