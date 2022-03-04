class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double t[102][102]= {0.0};
        
        t[0][0] = (double) poured;
        
        for(int i=0; i<=query_row; i++){
            for(int j = 0;j<=i; j++){
                double x = (double)(t[i][j] - 1.0)/2.0;
                if(x > 0){
                    t[i+1][j]+=x;
                    t[i+1][j+1] +=x;
                    t[i][j] = 1;
                }
            }
        }
        return t[query_row][query_glass];
    }
};